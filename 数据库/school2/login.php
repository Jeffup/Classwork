
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo "无敌数据库——课程设计"; ?></title>
<link rel="stylesheet" href="../css/install.css" />
</head>
<body>
<div class="wrap">
  <div class="section">
    <div class="step">
      <ul>    
        <li class="current" align='center'><em>✿</em>连接数据库</li>    
      </ul>
    </div>
    <form action="login_ok.php" method="post" >
      <div class="server">
        <table width="100%">
          <tr>
            <td class="td1" width="100">数据库信息</td>
            <td class="td1" width="200">&nbsp;</td>
            <td class="td1">&nbsp;</td>
          </tr>
		  <tr>
            <td class="tar">用户名：</td>
            <td><input type="text" name="a_name"/></td>
          </tr>
		  <tr>
		  </tr>
		  <tr>
            <td class="tar">密码：</td>
            <td><input type="password" name="a_password"/></td>
          </tr>
        </table>
        <div style="color:red;font-size:13px;"></div>
      </div>
        <div class="bottom tac">
		 <button type="submit" class="btn btn_submit J_install_btn">登录连接</button>
		 <button type="reset" class="btn btn_submit J_install_btn">重置</button>
		 <br><br>
   <a href="zhuce.php">注册页面</a></td>
  </div>
     
    </form>
  </div>
  <div  style="width:0;height:0;overflow:hidden;"> <img src="./images/install/pop_loading.gif"> </div>
</div>
</body>
</html>
