<?php
//链接数据库：地址，用户，密码，数据库名称
$servername="localhost";
$username="root";
$password="root";
$dbname="school";
$con=mysqli_connect($servername,$username,$password,$dbname);
if(!$con){
	die("数据库链接失败:".mysqli_connet_error($con));
	}
//设置字符集：utf8
mysqli_query($con,"set names utf8");

           					   
          
?>
