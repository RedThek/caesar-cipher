<?php

$message = "Santa Barbara";
$key = 3;
function encrypt(string $message, int $key): string
{
    $alphabet = 26;
    $encrypted_message = "";
    $key = $key % $alphabet;

    if($key < 0){
        $key = $alphabet + $key;
    }
    $key = $key + $alphabet;
    $encrypted_message = preg_replace_callback('/[a-zA-Z]/', function ($matches) use ($key, $alphabet) {
        $char = $matches[0];
        $base = ctype_lower($char) ? ord('a') : ord('A');
        $current_character = ord($char);
        $encrypted_character = ($current_character - $base + $key) % $alphabet + $base;
        return chr($encrypted_character);
    }, $message);

    return $encrypted_message;
}

function decrypt(string $message, int $key): string
{
    return encrypt($message, 26 - $key);
}

echo "Message = " . $message . ", Key = " . $key . "\n";

echo "Encrypted Message = " . encrypt($message, $key) . "\n";

echo "Decrypted Message = " . decrypt(encrypt($message, $key), $key);
