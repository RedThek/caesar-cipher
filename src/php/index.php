<?php

$message = "Formation Video";
$key = 3;
function encrypt(string $message, int $key): string
{
    $alphabet = 26;
    $encrypted_message = "";
    $message_length = strlen($message);

    if($key < 0){
        $key = $key + $alphabet;
    }

    for ($i = 0; $i < $message_length; $i++){
        if (ctype_alpha($message[$i])){
            if (ctype_lower($message[$i])){
                $base_character = ord('a');
                $current_character = ord($message[$i]);
                $encrypted_character = ($current_character - $base_character + $key) % $alphabet + $base_character;
                $encrypted_message = $encrypted_message.chr($encrypted_character);
            } elseif (ctype_upper($message[$i])) {
                $base_character = ord('A');
                $current_character = ord($message[$i]);
                $encrypted_character = ($current_character - $base_character + $key) % $alphabet + $base_character;
                $encrypted_message = $encrypted_message.chr($encrypted_character);
            } else {
                $encrypted_message = $encrypted_message.$message[$i];
            }
        } else {
            $encrypted_message = $encrypted_message.$message[$i];
        }
    }
    return $encrypted_message;
}

function decrypt(string $message, int $key): string
{
    $alphabet = 26;
    return encrypt($message, $alphabet - $key);
}

echo "Welcome to the Caesar cipher <br>";

echo "Message = " . $message . "<br>";

echo "Key = " . $key . "<br>";

echo "Encrypted Message = " . encrypt($message, $key) . "<br>";

echo "Decrypted Message is = " . decrypt(encrypt($message, $key), $key);
