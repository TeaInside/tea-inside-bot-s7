<?php

$php = "<?php ".trim(substr(file_get_contents(__FILE__), __COMPILER_HALT_OFFSET__));

$proc = proc_open(
    "php -d extension=".escapeshellarg(__DIR__."/../tg_icetea.so"),
    [
        ["pipe", "r"],
        ["file", "/dev/tty", "w"],
        ["file", "/dev/tty", "w"]
    ],
    $pipes
);


fwrite($pipes[0], $php);
fclose($pipes[0]);
proc_close($proc);

__halt_compiler();

$st = new TgIceTea\TgIceTea("test", "abc");
$st->process_update("test");

var_dump($st);
