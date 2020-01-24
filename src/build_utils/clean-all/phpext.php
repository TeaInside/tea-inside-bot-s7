<?php

$phpExtDir = $makeDir."/src/daemon/php";

/**
 * Clean phpize
 */

mmlog("phpize --clean...");
shchdir($phpExtDir);
sh("phpize --clean");
@unlink($phpExtDir."/build.lock");
