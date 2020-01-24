<?php

$daemonDir = $makeDir."/src/daemon";

/**
 * Build daemon section.
 */

// Build Makefile from Makefile.frag
mmlog("Building daemon...");
$fragFile = $daemonDir."/Makefile.frag";
if (!file_exists($fragFile)) {
	mmlog("Frag file does not exist: %s", $fragFile);
	exit(1);
}
$frag = file_get_contents($fragFile);
$frag = str_replace("~\$\$BASEDIR\$\$~", $daemonDir, $frag);
file_put_contents($daemonDir."/Makefile", $frag);
shchdir($daemonDir);
sh("make");

// Build phplink.sh from phplink.sh.frag
mmlog("Building php shared obj...");
$fragFile = $daemonDir."/phplink.sh.frag";
if (!file_exists($fragFile)) {
	mmlog("Frag file does not exist: %s", $fragFile);
	exit(1);
}
$frag = file_get_contents($fragFile);
$frag = str_replace("~\$\$BASEDIR\$\$~", $daemonDir, $frag);
file_put_contents($daemonDir."/phplink.sh", $frag);
shchdir($daemonDir);
sh("bash phplink.sh");
