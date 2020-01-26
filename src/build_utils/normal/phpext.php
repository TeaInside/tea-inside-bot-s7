<?php

$phpExtDir = $makeDir."/src/tg_icetea/php";

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
