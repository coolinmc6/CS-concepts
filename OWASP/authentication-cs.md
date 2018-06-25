# Authentication Cheat Sheet Notes

Based on OWASP's: [Authentication Cheat Sheet](https://www.owasp.org/index.php/Authentication_Cheat_Sheet)


### User IDs
1. Case insensitive
2. Email address as the UserID

### Passwords
The key concern is a **strong** password. The following criteria are **strong passwords**:

1. Minimum length of passwords (password length > 10 characters)
2. Maximum length cannot be too low (typical max length is 128 characters)
3. Password complexity should meet 3 of 4 criteria:
  	- at least 1 uppercase character (A-Z)
  	- at least 1 lowercase character (a-z)
  	- at least 1 digit (0-9)
  	- at least 1 special character (punctuation)
4. Ban commonly used passwords