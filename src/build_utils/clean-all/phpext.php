<?php

$phpExtDir = $makeDir."/src/tg_icetea/php";

/**
 * Clean phpize
 */

mmlog("phpize --clean...");
shchdir($phpExtDir);
sh("phpize --clean");
@unlink($phpExtDir."/build.lock");
