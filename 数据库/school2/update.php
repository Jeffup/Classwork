

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo "修改数据"; ?></title>
<link rel="stylesheet" href="../css/install.css" />
</head>
<body>

<?php 
// 数据库连接
include'conn.php';
include'conn2.php';
// 获取ID值
$s_id = $_REQUEST["s_id"];
$sql = "select * from student where s_id = " . $s_id; 
$result = mysqli_query($con,$sql); 
$row=mysqli_fetch_array($result);  
?>

<div class="wrap">
  <div class="section">
    <div class="step">
      <ul>    
        <li class="current" align='center'><em>✿</em>修改数据</li>    
      </ul>
    </div>
    <form action="update_ok.php" method="post" >
	<input type="hidden" name="id" value="<?php echo $row["s_id"];?>">
      <div class="server">
        <table width="100%">
          <tr>
            <td class="td1" width="100">数据信息</td>
            <td class="td1" width="200">&nbsp;</td>
            <td class="td1">&nbsp;</td>
          </tr>
		  <tr>
            <td class="tar">学号：</td>
            <td><input type="text" name="s_id" value="<?php echo $row["s_id"];?>"/></td>
          </tr>
		  		  <tr>
            <td class="tar">姓名：</td>
           <td><input type="text" name="s_name" value="<?php echo $row["s_name"];?>"/></td>
          </tr>
		  		  <tr>
            <td class="tar">性别：</td>
           <td>
      <select name="s_sex" style="width:150px">
      <option value="男" <?php if ($row["s_sex"]=="男"){ echo "selected='selected'";}?>>男</option>;
      <option value="女 "<?php if ($row["s_sex"]=="女"){ echo "selected='selected'";}?>>女</option>;
	  </select> 
    </td>
          </tr>
		  <tr>
            <td class="tar">班级：</td>
             <td><input type="text" name="s_class" value="<?php echo $row["s_class"];?>"/></td>
          </tr>
		  		  <tr>
            <td class="tar">手机：</td>
            <td><input type="text" name="s_phone" value="<?php echo $row["s_phone"];?>"/></td>
          </tr>
        </table>
        <div style="color:red;font-size:13px;"></div>
      </div>
        <div class="bottom tac">
		 <button type="submit" class="btn btn_submit J_install_btn">提交</button>
		 <button type="reset" class="btn btn_submit J_install_btn">重置</button>
		 <br><br>
   <a href="index.php">返回列表</a>
  </div>
     
    </form>
  </div>
  <div  style="width:0;height:0;overflow:hidden;"> <img src="./images/install/pop_loading.gif"> </div>
</div>
<?php
mysqli_close($con);
?>
</body>
</html>
