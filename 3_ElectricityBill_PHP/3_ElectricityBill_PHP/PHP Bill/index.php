<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>PHP Assignment</title>
    <link rel="stylesheet" href="bill.css">
</head>

<?php
$result_str='';
$result = '';
$str='';
if (isset($_POST['unit-submit'])) {
    $units = $_POST['units'];
    if (!empty($units)) {
        $result = calculate_bill($units);
        $result_str = 'So, The Total bill amount for '.$units.' units is : ₹'.$result;

        if($units >=0 && $units <= 50) {
            $str = nl2br("\r\n".$units." units lies in the range 1-50. Hence;\r\n").$units.' * 3.50 = '.$result ;
        }
        else if($units > 50 && $units <= 150) {
            $remaining_units = $units - 50;
            $str = nl2br("\r\n".$units." units lies in the range 51-150. Hence;\r\n").'50 * 3.50 + '.$remaining_units.' * 4.00 = '.$result ;
        }
        else if($units > 150 && $units <= 250) {
            $remaining_units = $units - 150;
            $str = nl2br("\r\n".$units." units lies in the range 151-250. Hence;\r\n").'50 * 3.50 + '.'100 * 4.00 + '.$remaining_units.' * 5.20 = '.$result ;
        }
        else if($units > 250) {
            $remaining_units = $units - 250;
            $str = nl2br("\r\n".$units." units is greater than 250. Hence;\r\n".'50 * 3.50 + '.'100 * 4.00 + '.'100 * 5.20 + '.$remaining_units.' * 6.50 = '.$result) ;

        }
    }
}
function calculate_bill($units) {
    $unit_cost_first = 3.50;
    $unit_cost_second = 4.00;
    $unit_cost_third = 5.20;
    $unit_cost_fourth = 6.50;

    if($units >=0 && $units <= 50) {
        $bill = $units * $unit_cost_first;
    }
    else if($units > 50 && $units <= 150) {
        $temp = 50 * $unit_cost_first;
        $remaining_units = $units - 50;
        $bill = $temp + ($remaining_units * $unit_cost_second);
    }
    else if($units > 150 && $units <= 250) {
        $temp = (50 * 3.5) + (100 * $unit_cost_second);
        $remaining_units = $units - 150;
        $bill = $temp + ($remaining_units * $unit_cost_third);
    }
    else if($units > 250) {
        $temp = (50 * 3.5) + (100 * $unit_cost_second) + (100 * $unit_cost_third);
        $remaining_units = $units - 250;
        $bill = $temp + ($remaining_units * $unit_cost_fourth);
    }
    else {
        return "Invalid";
    }
    return number_format((float)$bill, 2, '.', '');
}

?>

<body>
	<div id="page-wrap">
		<h1>Electricity Bill Calculator</h1>
        <div id="intro">
            <h3>The Electricity Bill will be generated based on following charges: </h3>
            <br>
            <ul>
                <li>For the first 50 units (<u>1-50 units</u>) the charge is <u>₹3.50 per unit</u></li>
                <li>For next 100 units (<u>51-150 units</u>) the charge is <u>₹4.00 per unit</u></li>
                <li>For next 100 units (<u>151-250 units</u>) the charge is <u>₹5.20 per unit</u></li>
                <li>For units <u>above 250</u> the charge is <u>₹6.50 per unit</u></li>
            </ul>
        </div>
		<form action="" method="post" id="quiz-form">
            	<input type="number" name="units" id="units" placeholder="Please enter number of Units" />
            	<input type="submit" name="unit-submit" id="unit-submit" value="Click to Generate Bill" />
		</form>
        
		<div id="cal">
            <h4>The Generated Electricity Bill is displayed here: </h4>
		    <?php echo $str; ?>
            <br><br>
            <div id="res">
                <?php echo $result_str; ?>
            </div>
            
		</div>
	</div>
</body>
</html>