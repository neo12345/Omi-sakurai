<?php
/* Get commission 
*
* input param $price
* input param $flg_detail
* input param Global G_tax
*
* return $commission
*/
function cal_commission($price, $flg_detail=""){
        global $G_tax;
		$G_tax = 8;
		
        if($price <= 200){
                $commission = $price * 0.05;
        }elseif($price <= 400){
                $commission = $price * 0.04 + 2;
        }else{
                $commission = $price * 0.03 + 6;
        }
        $commission = $commission * 10000;
        $commission = $commission * (1 + $G_tax/100);
        if($flg_detail){
                //$commission = floor($commission / 10) * 10;
        }else{
                $commission = floor($commission / 1000) / 10;
                $commission = sprintf("%.1f", $commission);
        }
        return $commission;
}


//------------------------------------------------------//
function _raise($location,$msg,$kind="function"){
	$format  ="<b style=\"color:#FF0000;\">ERROR!!</b> : [".$kind." <b>%s</b>]<br><div style=\"font-size:10pt;\">%s</div>";

	if($GLOBALS["G_is_debug"]){
		echo("<div style=\"font-family:'Courier New' font-size:15pt; border:3px double #FF0000; padding:5px; text-align:left; width:80%;\">");
		echo(sprintf($format,$location,$msg));
		echo('</div>');
	}else{
		$a[]="Location : ".$location;
		$a[]="Kind     : ".$kind;
		$a[]="Message  : ".$msg;
		$s=implode("\n",$a);
		$s=base64_encode($s);
		$s=wordwrap($s,50,"<br>",1);

		$s="<b style=\"color:#FF0000;\">Fatal Error Has Raised!!</b><br><div style=\"font-size:10pt;\">Error Code:<br>".$s."</div>";

		echo("<div style=\"font-family:'Courier New' font-size:15pt; border:3px double #FF0000; padding:5px; text-align:left; width:80%;\">");
		echo($s);
		echo('</div>');
	}

	exit;
}
//------------------------------------------------------//
function set_outer_param(){
	foreach($_REQUEST as $key=>$value){
		$F="F_".$key;
		global $$F;
		$$F=$value;
	}
	foreach($_SESSION as $key=>$value){
		$S="S_".$key;
		global $$S;
		$$S=$value;
	}
}
//------------------------------------------------------//
//------------------------------------------------------//
//------------------------------------------------------//
//------------------------------------------------------//
//------------------------------------------------------//
//------------------------------------------------------//
//------------------------------------------------------//
//------------------------------------------------------//
//------------------------------------------------------//
//------------------------------------------------------//
?>