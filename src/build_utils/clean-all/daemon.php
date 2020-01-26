<?php

$tgIceTeaDir = $makeDir."/src/tg_icetea";

/**
 * Clean tg_icetea section.
 */

// Build Makefile from Makefile.frag
mmlog("Cleaning tg_icetea...");
$fragFile = $tgIceTeaDir."/Makefile.frag";
if (!file_exists($fragFile)) {
	mmlog("Frag file does not exist: %s", $fragFile);
	exit(1);
}
$frag = file_get_contents($fragFile);
$frag = str_replace("~\$\$BASEDIR\$\$~", $tgIceTeaDir, $frag);
file_put_contents($tgIceTeaDir."/Makefile", $frag);
shchdir($tgIceTeaDir);
sh("make clean");
