<?php

require __DIR__."/src/build_utils/helpers.php";

$makeDir = __DIR__;

if (isset($argv[1])) {
    $buildType = $argv[1];
    if (!in_array($buildType, ["normal", "release", "clean"])) {
        mmlog("Invalid build type \"%s\"", $buildType);
        exit(1);
    }
} else {
    $buildType = "normal";
}

$buildQueues = [
    "daemon.php"
];

foreach ($buildQueues as $k => $v) {
    if (file_exists($f = __DIR__."/src/build_utils/".$buildType."/".$v)) {
        require $f;
    }
}
