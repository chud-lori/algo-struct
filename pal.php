<?php
function palindrome($value) {
    // only get alphabetical
    $value = preg_replace("/[^A-Za-z]/", '', $value);
    // lowercase
    $value = strtolower($value);
    $lenValue = strlen($value);

    $revname = [];

    for ($i=$lenValue-1; $i >= 0; $i--) {
        array_push($revname, $value[$i]);
    }

    if($value == implode("", $revname)) {
        return "Palindrome";
    }

    return "Not palindrome";
}

$args = [];
foreach(array_slice($GLOBALS['argv'], 1) as $arg ) {
    $args[] = $arg;
}
$value = implode("", $args);
$res = palindrome($value);

echo $res;
?>
