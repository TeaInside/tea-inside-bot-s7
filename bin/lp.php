<?php

$php = "<?php ".trim(substr(file_get_contents(__FILE__), __COMPILER_HALT_OFFSET__));

echo shell_exec(
    "/bin/echo ".escapeshellarg($php)." | php -d extension=".escapeshellarg(__DIR__."/../icetea_bot.so"));

__halt_compiler();

$st = new TeaBot\Daemon;
$st->run("test");
