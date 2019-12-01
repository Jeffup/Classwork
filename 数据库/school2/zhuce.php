<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>注册页面</title>
</head>
<link rel="stylesheet" href="../css/install.css" />
<script type="text/javascript">

//验证： 1 用户名不能为空，密码不能为空
function doCheck(){
	if(document.getElementById("a_name").value=="")
	{
		alert("用户名不能为空！");
		return false;
	}
	if(document.getElementById("a_password").value=="")
	{
		alert("密码不能为空！");
		return false;
	}
    if(document.getElementById("a_password").value!=document.getElementById("a_password2").value)
	{
		alert("两次密码输入不一致！");
		return false;
	}
	return true;
}
</script>

<body>
<div class="wrap">
  <div class="section">
    <div class="step">
      <ul>    
        <li class="current" align='center'><em>✿</em>注册页面</li>    
      </ul>
    </div>
    <form action="zhuce_ok.php" method="post" onSubmit="return doCheck()" >
      <div class="server">
        <table width="100%">
          <tr>
            <td class="td1" width="100">注册信息</td>
            <td class="td1" width="200">&nbsp;</td>
            <td class="td1">&nbsp;</td>
          </tr>
		  <tr>
            <td class="tar">用户名：</td>
          <td><input type="text" id="a_name" name="a_name"/></td>
          </tr>
		  <tr>
		  </tr>
		  <tr>
            <td class="tar">密码：</td>
             <td><input type="password" id="a_password" name="a_password"/></td>
          </tr>
		  <tr>
		  </tr>
		  <tr>
            <td class="tar">确认密码：</td>
             <td><input type="password" id="a_password2" name="a_password2"/></td>
          </tr>
        </table>
        <div style="color:red;font-size:13px;"></div>
      </div>
        <div class="bottom tac">
		 <button type="submit" class="btn btn_submit J_install_btn">提交</button>
		 <button type="reset" class="btn btn_submit J_install_btn">重置</button>
		 <br><br>
   <a href="login.php">登录页面</a></td>
  </div>
     
    </form>
  </div>
  <div  style="width:0;height:0;overflow:hidden;"> <img src="./images/install/pop_loading.gif"> </div>
</div>

</body>
</html>