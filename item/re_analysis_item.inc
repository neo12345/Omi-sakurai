<div class="right">
    <h2 class="PageTitle page01">物件管理</h2>
    <div class="tab_wrap clear">
      <ul class="tab">
        <li class="tab_off"><a href="/item/?md=list" title="物件一覧">物件一覧</a></li>
        <li class="tab_off"><a href="/item/?md=regist" title="物件登録">物件登録</a></li>
        <li class="tab_off"><a href="/item/?md=analysis" title="集計・解析">集計・解析</a></li>
        <li class="tab_on"><a href="/item/?md=analysis_item" title="解析(物件)">解析(物件)</a></li>

      </ul>
    </div>
    <div class="cnt_wrap">
        <div class="cnt_title clear w260"><h3>解析(物件)</h3></div>
        <div class="box-analysis">
            <div class="company-info">
            	<div class="col-left">
                	<div class="thumb-company"><img src="<?php echo $link_img_main_s; ?>" alt=""></div>
                    <table class="tbl-info">
                    	<tr>
                        	<th>販売価格</th>
                            <td><?php echo $RS_history[$count_history -1]['hist_price'];?>万円</td>
                        </tr>
                        <tr>
                        	<th>ステータス</th>
                            <td><?php echo $RS_history[$count_history -1]['stat_name'];?></td>
                        </tr>
                        <tr>
                        	<th>最終価格改定日</th>
                            <td>
								<?php 
									echo date('Y-m-d', strtotime($RS_history[$count_history -1]['date_regist']));
									echo '<br>（';							
									$today = time();
									$lastday = strtotime($RS_history[$count_history -1]['date_regist']);
									echo (floor(($today - $lastday) / 86400));
									echo '日前）';								
								?>
							</td>
                        </tr>
                    </table>
                    <div class="tbl-info-02">
                    	<table>
                        	<tr>
                            	<th>日付</th>
                                <th>ステータス</th>
                                <th>価格</th>
                                <th>担当</th>
                            </tr>
                           <?php for ($i = 0; $i < $count_history; $i++) { ?>
                                <tr>
                                    <td><?php echo date('Y/m/d', strtotime($RS_history[$i]['date_regist'])); ?></td>
                                    <td><?php echo $RS_history[$i]['stat_name']; ?></td>
                                    <td><?php echo $RS_history[$i]['hist_price']; ?> 万円</td>
                                    <td><?php //echo $RS_history[$i]['user_name'];    ?></td>
                                </tr>
                            <?php } ?>
                        </table>
                    </div>
                <!--/col-left--></div>
                <div class="col-right">
                	<table class="form-ccontact">
                    	<tr>
                        	<th>所在地</th>
                            <td colspan="3"><?php echo $RS_item[0]['item_name'];?></td>
                        </tr>
                        <tr>
                        	<th>価格</th>
                            <td colspan="3"><?php echo $RS_item[0]['item_price'];?>万円（税込）</td>
                        </tr>
                        <tr>
                        	<th>仲介手数料</th>phi moi gioi
                            <td colspan="3">839,160円 → 419,580円（仲介手数料上限から50%OFF）419,580円OFF</td>
                        </tr>
                        <tr>
                        	<th>土地面積</th>
                            <td>
								<?php
									if($RS_item[0]['item_size_land']) {
										echo $RS_item[0]['item_size_land'] . '㎡（';
										echo round($RS_item[0]['item_size_land'] * 0.302, 2) . '坪）';
									}
								?>	
							</td>
                            <th rowspan="2">諸費用</th>
                            <td rowspan="2">
								<?php
									if(!$RS_item[0]['item_cost_admin'] &&
									   !$RS_item[0]['item_cost_repair'] &&
									   !$RS_item[0]['item_park_min'] && 
									   !$RS_item[0]['item_park_max']) {
										echo '無し<br>';
									}
									if($RS_item[0]['item_cost_admin']) {
										echo '管理費			: '.$RS_item[0]['item_cost_admin'].'円<br>';
									}
									if($RS_item[0]['item_cost_repair']) {
										echo '修繕積立金		: '.$RS_item[0]['item_cost_repair'].'円<br>';
									}
									if($RS_item[0]['item_park_min']) {
										echo '物件駐車代上限	: '.$RS_item[0]['item_park_min'].'円<br>';
									}
									if($RS_item[0]['item_park_max']) {
										echo '物件駐車代下限	: '.$RS_item[0]['item_park_max'].'円<br>';
									}
									
								?>
							</td>
                        </tr>
                        <tr>
                        	<th>建築面積</th>
                            <td>
								<?php 
								if($RS_cat_item[0]['cat_item_cd'] == 1) {
									echo $RS_item[0]['item_size_build'] . '㎡（';								
								    echo round($RS_item[0]['item_size_build'] * 0.302, 2) . '坪）';
								} else {
									echo $RS_item[0]['item_size_floor'] . '㎡（';								
								    echo round($RS_item[0]['item_size_floor'] * 0.302, 2) . '坪）';
								}								
									if($RS_size_detail[0]) {
										for ($i = 0; $i < count($RS_size_detail) ; $i++) {
											echo '<br>' . $RS_size_detail[$i]['size_detail_name'];
											echo '	: '. $RS_size_detail[$i]['size_detail_size'] . '㎡';
										}
									}
								
								?>
							</td>
                        </tr>
                        <tr>
                        	<th>築年月</th>
                            <td><?php echo date('Y年m月', strtotime($RS_item[0]['item_build']));?></td>
                            <th rowspan="3">設備</th>
                            <td rowspan="3">
								ガス		：<?php echo $RS_fuel[0]['fuel_name']; ?><br>
								上水道	：<?php echo $RS_water[0]['water_name']; ?><br>
								下水道	：<?php echo $RS_sewer[0]['sewer_name']; ?>						
							</td>
                        </tr>
                        <tr>
                        	<th>間取り</th>
                            <td><?php echo $RS_layout[0]['layout_name'];?></td>
                        </tr>
                        <tr>
                        	<th>構造</th>
                            <td><?php echo $RS_structure[0]['struc_name'];?></td>
                        </tr>
                        <tr>
                        	<th>建ぺい率</th>
                            <td><?php echo $RS_item[0]['item_ratio_build'];?>%</td>
                            <th rowspan="2">交通</th>
                            <td rowspan="2">
								<?php 
									echo $RS_pubtrans[0]['pubtrans_name'];
									echo ' 「';
									echo $RS_stop[0]['stop_name'];
									echo '」 駅まで';
									echo $RS_transway[0]['transway_name'];
									echo $RS_transtime[0]['transtime'];
									echo '分';
								?>
							</td>
                        </tr>
                        <tr>
                        	<th>容積率</th>
                            <td><?php echo $RS_item[0]['item_ratio_floor'];?>%</td>
                        </tr>
                        
                        <tr>
                        	<th>総戸数・建物階数</th>
                            <td>
							<?php
								if($RS_cat_item[0]['cat_item_cd'] == 1 ) {
									echo $RS_item[0]['item_houses'];
								} else {
									echo $RS_item[0]['item_floor_above'] + $RS_item[0]['item_floor_under'];
								} 
							?>
							</td>
                            <th rowspan="3">学校</th>
                            <td rowspan="3">
								<?php 
									if($RS_school_pri[0]) {
										echo $RS_school_pri[0]['school_pri_name'];
										echo '	: ';
										echo $RS_item[0]['item_dist_pri'] . 'm';
										echo '(' . $RS_item[0]['item_min_pri'] . '分）';
										echo '<br>';
									}
									if($RS_school_jun[0]) {
										echo $RS_school_jun[0]['school_jun_name'];
										echo '	: ';
										echo $RS_item[0]['item_dist_jun'] . 'm';
										echo '(' . $RS_item[0]['item_min_jun'] . '分）';
										echo '<br>';
									}
									if($RS_cat_schigh[0]) {
										echo '高校学区	: ';
										echo $RS_cat_schigh[0]['cat_schigh_name'];
									}
								?>
							</td>
                        </tr>
                        <tr>
                        	<th>駐車場</th>
                            <td>
							<?php
								if($RS_cat_item[0]['cat_item_cd'] == 1 ) {
									echo $RS_item[0]['item_park_in'];
								} else {
									echo $RS_item[0]['item_park_vacancy'];
								}
							?> 
							</td>
                        </tr>
                        <tr>
                        	<th>接道</th>
                            <td>
								<?php
									for ($i = 0; $i < count($RS_road); $i++) { 
										echo $RS_road[$i]['dire_name'] . '側';
										echo $RS_road[$i]['along_size'] . 'm';
										echo $RS_road[$i]['road_name'] . '<br>';
									}
								?>
							</td>
                        </tr>
                        <tr>
                        	<th>土地権利</th>
                            <td><?php echo $RS_rights[0]['rights_name'];?></td>
                            <th>地目</th>
                            <td><?php echo $RS_landcat[0]['landcat_name'];?></td>
                        </tr>
                        <tr>
                        	<th>都市計画</th>
                            <td><?php echo $RS_plan[0]['plan_name'];?></td>
                            <th>用途地域</th>
                            <td><?php echo $RS_district[0]['dist_name'];?></td>
                        </tr>
                        <tr>
                        	<th>建築確認番号</th>
                            <td><?php echo $RS_item[0]['item_serial'];?></td>
                            <th>取引形態</th>
                            <td><?php echo $RS_method[0]['meth_name'];?></td>
                        </tr>
                        <tr>
                        	<th>その他制限等</th>
                            <td><?php echo $RS_item[0]['item_restrict'];?></td>
                            <th rowspan="2">地図</th>
                            <td rowspan="2">
                            	<input type="hidden" id="lat" value="<?php echo $RS_item[0]['x_item_lat']; ?>"/>
                                <input type="hidden" id="lng" value="<?php echo $RS_item[0]['x_item_lng']; ?>"/>
                                <input type="hidden" id="zoom" value="<?php echo $RS_item[0]['item_zoom']; ?>"/>
                                <div class="map-company" id="googleMap" style="width: 90% ;height: 300px; padding: 20px;"></div>
                            </td>
                        </tr>
                        <tr>
                        	<th>特記事項</th>
                            <td><?php echo str_replace(" ", "<br>", $RS_item[0]['item_memo']);?></td>
                        </tr>
                    </table>
                </div>
                <div class="clear"></div>
            <!--/company-info--></div>
            <div class="line-chart">
            	<h4 class="mtit">イベント・販売価格変動</h4>
            	
                <div class="view-chart">
					<input type="hidden" id="item_cd" value="<?php echo $RS_item[0]['item_cd']; ?>">
                	<div id="chart_div"></div>
				</div>
            <!--/line-chart--></div>
        <!--/tabl-box-analysis--></div>
    </div>
  </div>


<!--STYLE CSS NEW-->
<link href="/_css/style-new.css" rel="stylesheet" type="text/css">

<!--Load jquery, bootstrap-->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.2/jquery.min.js"></script>
<script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>

<!--Load google chart-->
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script type="text/javascript">google.charts.load('current', {'packages': ['corechart']});</script>
<script src="/_js/item/analysis_item_chart.js" type="text/javascript"></script>

<!--Load google maps api-->
<script src="http://maps.googleapis.com/maps/api/js"></script>
<script>
    function initialize() {
        var lat = $('#lat').val();
        var lng = $('#lng').val();
        var zoom = parseInt($('#zoom').val());

        var mapProp = {
            center: new google.maps.LatLng(lat, lng),
            zoom: zoom,
            mapTypeId: google.maps.MapTypeId.ROADMAP,
        };

        var map = new google.maps.Map(document.getElementById("googleMap"), mapProp);

        var marker = new google.maps.Marker({
            position: new google.maps.LatLng(lat, lng),
        });

        marker.setMap(map);
    }
    google.maps.event.addDomListener(window, 'load', initialize);
</script>