<!DOCTYPE html>

<?php
//Turning of warnings on page
error_reporting(0);

/* script sending data from first cell of form into C script for processing 
and saving resaults as variable */

//check if form was submitted
if(isset($_POST['Sub'])){
    $output=null;
    $retval=null;
    $value_bin=$_POST['Bin'];
    $value_oct=$_POST['Oct'];
    $value_dec=$_POST['Dec'];
    $value_hex=$_POST['Hex'];


    //allowing only one of numeral types to be passed at same time
    $bin = false;
    $oct = false;
    $dec = false;
    $hex = false;

    $input_type = 0;
    $value;

    if(!empty($value_bin)) {$bin = true; $input_type = 1; $value = $value_bin;}
    if(!empty($value_oct)) {$oct = true; $input_type = 2; $value = $value_oct;}
    if(!empty($value_dec)) {$dec = true; $input_type = 3; $value = $value_dec;}
    if(!empty($value_hex)) {$hex = true; $input_type = 4; $value = $value_hex;}

    exec("calculator.exe $value $input_type", $output, $retval);
}?>







<html>
    <head>
        <title>Numeral system calculator</title>
        <meta Charset="UTF-8">
    </head>
    <body>
    
    
    <form action="index.php" method="post">

    Bin: <input type="text" name="Bin"
    placeholder=<?php 
    if(empty($value_bin)) {Echo("00000000000000000000000000000000");}
    else {Echo($value_bin);}?>
    <?php if($oct||$dec||$hex) {Echo("Disabled");} ?>><br>

    Oct: <input type="text" name="Oct"
    placeholder=<?php
    if(empty($value_oct)) {Echo("00000000000");}
    else {Echo($value_oct);}?>
    <?php if($bin||$dec||$hex) {Echo("Disabled");} ?>><br>

    Dec: <input type="text" name="Dec"
    placeholder=<?php
    if(empty($value_dec)) {Echo("0000000000");}
    else {Echo($value_dec);}?>
    <?php if($bin||$oct||$hex) {Echo("Disabled");} ?>><br>

    Hex: <input type="text" name="Hex"
    placeholder=<?php
    if(empty($value_hex)) {Echo("00000000");}
    else {Echo($value_hex);}?>
    <?php if($bin||$oct||$dec) {Echo("Disabled");} ?>><br>

    <input type="submit" name="Sub">
    </form>
    

    
    <?php
    //printing out resault of C script
    print_r($output);
    ?>

    </body>
</html>