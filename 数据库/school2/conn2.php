<?php //判断是否登录

 
if (isset($_COOKIE["a_name"])){
	
	 return true;
	
	}else{
		
	 echo "<script>alert('无操作权限,请重新登录');location.href='login.php';</script>";	
	 
	} 
        
?>