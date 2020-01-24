<?php

$phpExtDir = $makeDir."/src/daemon/php";

/**
 * Phpize
 */

if (!file_exists($phpExtDir."/build.lock")) {
    mmlog("phpize && ./configure && make");
    shchdir($phpExtDir);
    sh("phpize");
    sh("./configure");
    sh("make");
    file_put_contents($phpExtDir."/build.lock", time());
}
