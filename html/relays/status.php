<?php
require 'relays.php';
	$devices = "abcdefghijk";
	$res = "";
	for($i=0; $i<strlen($devices); $i++) {
		$devStatus ="";
		$fn = $devices[$i] . ".status";
		if (file_exists($fn)) {
			$devStatus = substr(file_get_contents($fn), 0, 1);
		} 
		if ($devStatus == "") {
			$devStatus = strtoupper($devices[$i]);  // By default, off
		}
		$res .= $devStatus;
	}
	switchRelays($res, false);
	echo $res;
?>