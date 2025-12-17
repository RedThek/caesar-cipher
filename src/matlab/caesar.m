function encrypted = caesar_encrypt(text, key)
    % key: integer shift value (0-25)
    
    key = mod(key, 26);
    
    encrypted = char(zeros(1, length(text)));
    for i = 1:length(text)
        c = text(i);
        if c >= 'A' && c <= 'Z'
            encrypted(i) = char(mod((c - 'A') + key, 26) + 'A');
        elseif c >= 'a' && c <= 'z'
            encrypted(i) = char(mod((c - 'a') + key, 26) + 'a');
        else
            encrypted(i) = c;
        end
    end
end

function decrypted = caesar_decrypt(text, key)
    caesar_encrypt(text, 26 - key);
end
