<?php

$tgIceTeaDir = $makeDir."/src/tg_icetea";

/**
 * Build tg_icetea section.
 */

// Build Makefile from Makefile.frag
mmlog("Building tg_icetea...");
$fragFile = $tgIceTeaDir."/Makefile.frag";
if (!file_exists($fragFile)) {
	mmlog("Frag file does not exist: %s", $fragFile);
	exit(1);
}
$frag = file_get_contents($fragFile);
$frag = str_replace("~\$\$BASEDIR\$\$~", $tgIceTeaDir, $frag);
file_put_contents($tgIceTeaDir."/Makefile", $frag);
shchdir($tgIceTeaDir);
sh("make");

// Build phplink.sh from phplink.sh.frag
mmlog("Building php shared obj...");
$fragFile = $tgIceTeaDir."/phplink.sh.frag";
if (!file_exists($fragFile)) {
	mmlog("Frag file does not exist: %s", $fragFile);
	exit(1);
}
$frag = file_get_contents($fragFile);
$frag = str_replace("~\$\$BASEDIR\$\$~", $tgIceTeaDir, $frag);
file_put_contents($tgIceTeaDir."/phplink.sh", $frag);
shchdir($tgIceTeaDir);
sh("bash phplink.sh");

shchdir($makeDir);
sh("ln -svf src/tg_icetea/php/modules/tg_icetea.so .");
