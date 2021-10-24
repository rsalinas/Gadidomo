<?php

/*
	a: luces generales (GPIO 2)
	b: tira LED
	c: persiana norte
	d: persiana este	 
	e: persiana oeste
	f: pantalla 1
	g: pantalla 2
	h: pantalla 3
	i: 
	j: 
	k: 
*/

function switchRelays($cmd) {
	 for($i=0; $i<strlen($cmd); $i++) {
		 $c = $cmd[$i];
		 // write to the file DEVICE.status
		 file_put_contents(strtolower($c) . ".status", $c);
	 }
	$port = "com3";
	shell_exec("mode $port: BAUD=9600 PARITY=n DATA=8 STOP=1 to=off dtr=off rts=off > nul:");
	try {
	  $fp =fopen($port, "w"); 
	  fwrite($fp, $cmd);
	  fflush($fp);
	} finally {
	  fclose($fp);
	}
}

if (php_sapi_name() == "apache2handler" && array_key_exists("relayAction", $_POST)) {
		switchRelays($_POST["relayAction"]);
}

?>
