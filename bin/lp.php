<?php

$php = "<?php ".trim(substr(file_get_contents(__FILE__), __COMPILER_HALT_OFFSET__));

$proc = proc_open(
    "php -d extension=".escapeshellarg(__DIR__."/../tg_icetea.so"),
    [
        ["pipe", "r"],
        ["file", "/dev/tty", "w"],
        ["file", "/dev/tty", "w"]
    ],
    $pipes,
    __DIR__
);


fwrite($pipes[0], $php);
fclose($pipes[0]);
proc_close($proc);

__halt_compiler();

require __DIR__."/../config.php";

$st = new TgIceTea\TgIceTea(BOT_TOKEN, BOT_USERNAME);

$lastUpdateId = 0;

while (true) {
    $ch = curl_init("https://api.telegram.org/bot".BOT_TOKEN."/getUpdates?offset=".($lastUpdateId + 1));
    curl_setopt_array($ch,
        [
            CURLOPT_RETURNTRANSFER => true,
            CURLOPT_SSL_VERIFYPEER => false,
            CURLOPT_SSL_VERIFYHOST => false
        ]
    );
    $o = json_decode(curl_exec($ch), true);
    curl_close($ch);
    
    if (!$o["ok"]) {
        echo json_encode($o, JSON_UNESCAPED_SLASHES | JSON_PRETTY_PRINT);
        exit(1);
    }

    $hasUpdate = false;

    foreach ($o["result"] as $k => $v) {
        if ($v["update_id"] > $lastUpdateId) {
            $hasUpdate = true;
            $lastUpdateId = $v["update_id"];
            echo "Processing ".$v["update_id"]."\n";
            $st->process_update(json_encode($v, JSON_UNESCAPED_SLASHES));
        }
    }

    if (!$hasUpdate) {
        echo "No update\n";
    }

    sleep(1);
}
