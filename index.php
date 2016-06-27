<?php
//-- configインクルード --//
include("_common/config.php");
//--ステータス--//
check_login();

header("location:/item/");
exit;


//-- .inc --//
include("_common/header.inc");
include($inc);
include("_common/footer.inc");
exit;
?>