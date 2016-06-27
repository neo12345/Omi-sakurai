
  <div class="right">
    <h2 class="PageTitle page01">物件管�?�</h2>
    <div class="tab_wrap clear">
      <ul class="tab">
        <li class="tab_on"><a href="/item/?md=list" title="物件一覧">物件一覧</a></li>
        <li class="tab_off"><a href="/item/?md=regist" title="物件登録">物件登録</a></li>
        <li class="tab_off"><a href="/item/?md=analysis" title="集計・解�?">集計・解�?</a></li>
        <li class="tab_off"><a href="/item/?md=analysis_item" title="解�?(物件)">解�?(物件)</a></li>
      </ul>
    </div>
    <div class="cnt_wrap">
      <div class="cnt_title clear w260">
        <h3>物件一覧</h3>
<!--        <input type="button" value="追加" id="js_add" class="btn_add btn_style_01" />-->
      </div>
			<form method="post" action="/item/?md=regist" class="js_unsubmit">
				<? shot_select("city_cd", $F_city_cd, "", $RS_city, "city_cd", "city_name", "id=\"js_city_cd\"", "全�?��?�エリア"); ?>
				<? shot_select("stat_cd", $F_stat_cd, "", $A_stat, "stat_cd", "stat_name", "id=\"js_stat_cd\"", "-----"); ?>
				<?php shot_select("seller_cd", $F_seller_cd, "", $RS_seller, "seller_cd", "seller_name", "id=\"js_seller_cd\"", "-----"); ?>
				<?php shot_select("seller_office_cd", $F_seller_office_cd, "", $RS_seller_office, "seller_office_cd", "seller_office_name", "id=\"js_seller_office_cd\"", "-----"); ?>
				<? shot_select("stat_item_cd", $F_stat_item_cd, "", $A_stat_item, "stat_item_cd", "stat_item_name", "id=\"js_stat_item_cd\"", "-----"); ?>
				<input id="js_serach_name" type="text" value="<?= $F_search_name ?>" placeholder="物件�??･�?所･学校�??･駅�??" style="width: 300px;" />
				<?php if($F_type_search == "or"){ $checked_and = ""; $checked_or = "checked"; }else{ $checked_and = "checked"; $checked_or = ""; } ?>
				<input type="radio" name="type_search" value="and" <?= $checked_and ?> />AND  <input type="radio" name="type_search" value="or" <?= $checked_or ?> />OR
				<input id="js_search" type="button" value=" 検 索 " />
				<table class="table_style">
					<thead>
						<tr>
							<td>No.</td>
							<td>登録日</td>
							<td>物件�??</td>
							<th>新/�?�</th>
							<th>築年</th>
							<td>売主</td>
							<td>売主TEL</td>
							<td>�?所</td>
							<td>沿線･駅</td>
							<td>学校</td>
							<td>価格</td>
							<th>水�?�下</th>
							<th>PDF</th>
							<td class="btn_tbl_with">詳細</td>
							<td class="btn_tbl_with">状態</td>
							<td class="btn_tbl_with">編集</td>
							<td class="btn_tbl_with">削除</td>
						</tr>
					</thead>
					<tbody id="js_list">
						<? for ($i = 0; $i < /*count($RS_item)*/10; $i++) : ?>
							<? if($RS_item[$i]['flg_soldout']){ $color="silver"; $status="�?"; }elseif($RS_item[$i]['flg_nego']){ $color="pink"; $status="商"; }else{ $color="white"; $status="販"; } ?>
							<tr class="js_colum" style="background-color: <?= $color ?>;">
								<td class="no"><?= $RS_item[$i]['item_cd'] ?><input type="hidden" class="js_item_cd" value="<?= $RS_item[$i]['item_cd'] ?>" /></td>
								<td class="no"><?= pic_object_date("Y/m/d", $RS_item[$i]['date_regist']) ?></td>
								<td>
									<?php
										if(date("Y-m-01", strtotime("+1 month")) < $RS_item[$i]['item_build'] and $RS_item[$i]['item_build'] < date("Y-m-01", strtotime("+2 month"))){
											$status_build = "未完�?";
										}elseif(date("Y-m-01") < $RS_item[$i]['item_build'] and $RS_item[$i]['item_build'] < date("Y-m-01", strtotime("+1 month"))){
											$status_build = "完�?月";
										}elseif($RS_item[$i]['item_build'] >= date("Y-m-01", strtotime("+2 month"))){
											$status_build = "完�?予定";
										}else{
											$status_build = "";
										}
									?>
									<? if($RS_item[$i]['flg_active']): ?>
										<a href="http://www.smile-fudosan.com/item/?md=detail&cd=<?= $RS_item[$i]['item_cd'] ?>&qwert=1" target="_blank">
											<?= $RS_item[$i]['item_name'] ?><? if($RS_item[$i]['item_name_sub']): ?>（<?= $RS_item[$i]['item_name_sub'] ?>）<? endif; ?><? if($status_build): ?>�?<?= $status_build ?>】<? endif; ?>
										</a>
									<? else: ?>
										<?= $RS_item[$i]['item_name'] ?><? if($RS_item[$i]['item_name_sub']): ?>（<?= $RS_item[$i]['item_name_sub'] ?>）<? endif; ?><? if($status_build): ?>�?<?= $status_build ?>】<? endif; ?>
									<? endif; ?>
									<input type="hidden" class="js_item_name" value="<?= $RS_item[$i]['item_name'] ?>" />
									<? get_rs("r_item10", "chase", "item_cd='".$RS_item[$i]['item_cd']."'", "rel_cd asc"); ?>
									<? for ($j = 0; $j < count($RS_chase); $j++) : ?>
										<img src="<?= $G_img_dir ?>/common/ico_user_<?= sprintf("%02d", $RS_chase[$j]['user_cd']) ?>.png" />
									<? endfor; ?>
								</td>
								<td class="tac">
									<? if($RS_item[$i]['flg_new']): ?>
										新築
									<? else: ?>
										中�?�
									<? endif; ?>
								</td>
								<td><?= pic_object_date("Y/m", $RS_item[$i]['item_build']) ?></td>
								<td><?= $RS_item[$i]['seller_name'] ?><?php if($RS_item[$i]['seller_office_cd']){ echo "(".$RS_item[$i]['seller_office_name'].")"; } ?></td>
								<td>
									<? if($RS_item[$i]['seller_office_cd']): ?>
										<?= $RS_item[$i]['seller_office_tel'] ?>
									<? elseif($RS_item[$i]['seller_cd']): ?>
										<?= $RS_item[$i]['seller_tel'] ?>
									<? endif; ?>
								</td>
								<td>
									<?= $RS_item[$i]['pref_name'] ?><?= $RS_item[$i]['city_name'] ?><?= $RS_item[$i]['item_addr2'] ?><?= $RS_item[$i]['item_addr3'] ?>
									<? if($RS_item[$i]['item_addr_under']): ?><br />（<?= $RS_item[$i]['item_addr_under'] ?>）<? endif; ?>
								</td>
								<td>
									<? get_rs("r_item2", "item_pub", "item_cd='".$RS_item[$i]['item_cd']."'", "rel_cd asc"); ?>
									<? for ($j = 0; $j < count($RS_item_pub); $j++) : ?>
										<? if($RS_item_pub[$j]['stop_cd']): ?>
											<? get_rs("v_stop", "stop", "stop_cd='".$RS_item_pub[$j]['stop_cd']."'", ""); ?>
											<? if($j>0): ?><br /><? endif; ?>
											<?= $RS_stop[0]['pubtrans_name'] ?>：<?= $RS_stop[0]['stop_name'] ?>
										<? endif; ?>
									<? endfor; ?>
								</td>
								<td>
									<? $school_pri_name = preg_replace("/^.+市立/", "", $RS_item[$i]['school_pri_name']); ?>
									<? $school_jun_namee = preg_replace("/^.+市立/", "", $RS_item[$i]['school_jun_name']); ?>
									<?= $school_pri_name ?><br />
									<?= $school_jun_namee ?><br />
									<?= $RS_item[$i]['cat_schigh_name'] ?>
								</td>
								<td class="tar">
									<span class="js_item_price" style="cursor: pointer;"><?= number_format($RS_item[$i]['item_price']) ?>万円</span>
									<div class="js_price_frame dn">
										<input class="js_value" style="width: 35px;" type="text" value="<?= $RS_item[$i]['item_price'] ?>" />
										<span class="js_regist fsSx curp">登録</span>
									</div>
								</td>
								<td class="tar">
									<? if($RS_item[$i]['item_price_under']): ?>
										<?= number_format($RS_item[$i]['item_price_under']) ?>万円
									<? else: ?>
										----万円
									<? endif; ?>
								</td>
								<td class="tac">
									<? if(is_file($G_root_path."/_up/item/".sprintf("%03d", $RS_item[$i]['item_cd'])."/fact.pdf")): ?>
										<?= number_format($RS_item[$i]['count_pdf']) ?>
									<? else: ?>
										未登録
									<? endif; ?>
								</td>
								<td><input class="js_detail" style="width: 20px;" type="button" value="詳細" /></td>
								<td><input class="js_status" style="width: 20px;" type="button" value="<?= $status ?>" /></td>
								<td class="edit"><input type="submit" name="edit[<?= $RS_item[$i]['item_cd'] ?>]" value="編集" class="btn_edit btn_style_02" /></td>
								<td class="del"><input type="button" value="削除" class="js_delete btn_delete btn_style_02" /></td>
							</tr>
						<? endfor; ?>
					</tbody>
				</table>
			</form>
    </div>
  </div>