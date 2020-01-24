<?php

require __DIR__."/src/build_utils/helpers.php";

$daemonDir = __DIR__."/src/daemon";

/**
 * Build daemon section.
 */

// Build Makefile from Makefile.frag

$fragFile = $daemonDir."/Makefile.frag";
if (file_exists($fragFile)) {
	mmlog("Frag file does not exist: %s", $fragFile);
	exit(1);
}

$frag = file_get_contents($fragFile);