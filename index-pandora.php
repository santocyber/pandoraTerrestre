<!-- 
 conteudo deste script (hugreen.solar) esta sob licenca Creative Commons 

sudo chmod a+rw /dev/ttyACM0
"r+b" seria permissão para leitura e escrita na porta.



$port=fopen($portAdress,"r+b");

 -->

<html>
    <head>
        <meta http-equiv="Content-Language" content="pt-br" />
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <meta name="http://x.mirako.org" />
    <title>Proteus Robot Hugreen.Solar</title>
    </head>
    <body>
        <body bgcolor="#D4D2D2">
        
<h1>
Proteus Robot Hugreen.Solar
</h1>

<?php
$address2 = $_SERVER['SERVER_ADDR'];
$address =  str_replace(':8081', '', $_SERVER['HTTP_HOST']);


if( $address == '192.168.1.70:8888') {
  $domain = $_SERVER['SERVER_ADDR'];

} 
else {
$domain = str_replace(':8888', '', $_SERVER['HTTP_HOST']);  
}  

?>

 <iframe frameborder="0" marginheight="0" marginwidth="0" scrolling="no"   src = "http://<?php echo "$domain"?>:8081" width="640" height="480" ></iframe> 

<!--

 <iframe frameborder="0" marginheight="0" marginwidth="0" scrolling="no"   src = "http://<?php echo "$domain"?>:8081" width="320" height="240" ></iframe> 
 <iframe frameborder="0" marginheight="0" marginwidth="0" scrolling="no"   src = "http://panfilo.noip.us:8081" width="320" height="240" ></iframe> 
-->

<br><br>

<?php


    $port = fopen("/dev/ttyUSB0", "r+b");

      if ($_POST['situacao']=="Acionar")
      {
      fwrite($port, "e");
      }

    //header ("Location: http://localhost/index.php");
      if ($_POST['situacao']=="reset")
      {
      fwrite($port, "90g");
      }

    //header ("Location: http://localhost/index.php");
      if ($_POST['situacao']=="temp")
      {
      fwrite($port, "h");
echo fgets($port);      
fclose($port);
      }

    //header ("Location: http://localhost/index.php");
      if ($_POST['situacao']=="ultrasom")
      {
      fwrite($port, "f");
echo fgets($port);      

      }

    //header ("Location: http://localhost/index.php");

      if ($_POST['situacao']=="frente")
      {
      fwrite($port, "w");
      }
      if ($_POST['situacao']=="reh")
      {
      fwrite($port, "s");
      }
      if ($_POST['situacao']=="direita")
      {
      fwrite($port, "d");
      }
      if ($_POST['situacao']=="esquerda")
      {
      fwrite($port, "a");
      }
      if ($_POST['situacao']=="laser")
      {
      fwrite($port, "l");
      }
      if ($_POST['situacao']=="bibi")
      {
      fwrite($port, "b");
      }


    //header ("Location: http://localhost/index.php");

fclose($port);

?>


<table border="0" cellpadding="0" cellspacing="0" style="width: 12%;">
<tbody>
<tr>

<form method="POST" action="index.php">

        <input type="hidden" value="frente" name="situacao">
        <input type="submit" value="Frente" name="frente" style="border-color:black; border-style: solid;border-width: 5; background-color: green; color: white;height: 45px; font-size:35px">
</form>

<form method="POST" action="index.php">
        <input type="hidden" value="esquerda" name="situacao">
        <input type="submit" value="Esquerda" name="esquerda" style="border-color:black; border-style: solid;border-width: 5; background-color: green; color: white;height: 45px; font-size:35px">

</form>

<form method="POST" action="index.php">

        <input type="hidden" value="direita" name="situacao">
        <input type="submit" value="Direita" name="direita" style="border-color:black; border-style: solid; border-width: 5; background-color: green; color: white;height: 45px; font-size:35px">
        </form>



<form method="POST" action="index.php">
        <input type="hidden" value="reh" name="situacao">
        <input type="submit" value="Reh" name="reh" style="border-color:black; border-style: solid;border-width: 5; background-color: green; color: white;height: 45px; font-size:35px">
</form>
</td>
</tr>
<tr></tr>
<br>

        <td>    
<br><br>
<!-- LASER -->

<form method="POST" action="index.php">

        <input type="hidden" value="laser" name="situacao">
        <input type="submit" value="Laser" name="laser" style="border-color:black; border-style: solid; border-width: 1; background-color: 
green; color: white">

</form>
        </td>    

    <tr>
        <td>

<!-- TEMP -->

<form method="POST" action="index.php">

        <input type="hidden" value="temp" name="situacao">
        <input type="submit" value="Temperatura" name="temp" style="border-color:black; border-style: solid; border-width: 1; background-color: 
green; color: white">

</form>
        </td>    

    <tr>
        <td>

        </td>    

    <tr>
        <td>

<!-- HINO -->

<form method="POST" action="index.php">

        <input type="hidden" value="bibi" name="situacao">
        <input type="submit" value="BiBi" name="bibi" style="border-color:black; border-style: solid; border-width: 1; background-color: 
green; color: white">
</form>


        <p><a href="http://x.mirako.org" target="_blank">http://x.mirako.org</a></p>
        <p>v.0.9.3</p>
    </body>
</html>
