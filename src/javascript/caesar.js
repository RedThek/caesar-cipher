function encrypt(message, key) {
    let result = '';
    for (let char of message) {
        if (char >= 'A' && char <= 'Z') {
            result += String.fromCharCode(((char.charCodeAt(0) - 65 + key) % 26) + 65);
        } else if (char >= 'a' && char <= 'z') {
            result += String.fromCharCode(((char.charCodeAt(0) - 97 + key) % 26) + 97);
        } else {
            result += char;
        }
    }
    return result;
}

function decrypt(message, key) {
    return encrypt(message, 26 - (key % 26));
}
console.log('Encrypt "Hello World" with key 3:', encrypt('Hello World', 3));
console.log('Decrypt "Khoor Zruog" with key 3:', decrypt('Khoor Zruog', 3));