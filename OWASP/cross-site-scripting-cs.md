[Back to all cheat sheet notes](https://github.com/coolinmc6/CS-concepts/tree/master/OWASP)

# XSS (Cross Site Scripting) Prevention Cheat Sheet

Based on OWASP's: [XSS (Cross Site Scripting) Prevention Cheat Sheet](https://www.owasp.org/index.php/XSS_(Cross_Site_Scripting)_Prevention_Cheat_Sheet)

### Intro

- **Cross-Site Scripting (XSS)** attacks are a type of *injection* where the attacker injects a malicious script into a trusted website.
- XSS attacks can happen when the attackers uses a web application (i.e. a social network) to send the malicious code (generaly in the form of a browser-side script) that the web app is tricked into executing
- The end user's browser doesn't know to NOT execute the script
- 

### XSS Prevention Rules

0. Never insert untrusted data except in allowed locations. Here are some examples:
    - directly in a script: `<script> UNTRUSTED DATA </script>`
    - inside an HTML comment: `<!-- UNTRUSTED DATA -->`
    - inside an attribute name: `<div UNTRUSTED_DATA="" />`
    - in a tag name: `<UNTRUSTED_DATA />`
    - directly in CSS: `<style> UNTRUSTED DATA </style>`
1. HTML escape before inserting untrusted data into HTML element content
    - &, <, >, ", ', / are all characters that must be escaped
    - `<div class="user-comment">ESCAPE THIS CONTENT</div>` => anything the user is inputting and then you, as a developer, are then putting into an HTML element for your users to see, MUST be escaped
2. Attribute escape before inserting untrusted data into HTML common attributes
    - exactly like the one above but for HTML attributes (i.e. href, title, name, whatever!!)
3. JavaScript escape before inserting untrusted data into JavaScript data values
    - `window.setInterval(' UNTRUSTED DATA ')` => you can never safely use untrusted data as input, even if you escape it
4. CSS Escape and strictly validate before inserting untrusted data into HTML style property values
5. URL escape before inserting untrusted data into HTML URL parameters
    - if creating a link with untrusted data, escape it!
6. Sanitize HTML markup with a library designed for the job
7. Prevent DOM-based XSS
    - see [DOM based XSS Prevention Cheat Sheet](https://www.owasp.org/index.php/DOM_based_XSS_Prevention_Cheat_Sheet)
    - GUIDELINE #1 - Untrusted data should only be treated as displayable text
    - GUIDELINE #2 - Always JavaScript encode and delimit untrusted data as quoted strings when entering the application when building templated Javascript
    - GUIDELINE #3 - Use document.createElement("..."), element.setAttribute("...","value"), element.appendChild(...) and similar to build dynamic interfaces
    	+ element.setAttribute() is only safe for a limited number of attributes (click link above to see list; it's actually a pretty good size)
    - GUIDELINE #4 - Avoid sending untrusted data into HTML rendering methods
		- `element.innerHTML = "...";`
		- `element.outerHTML = "...";`
		- `document.write(...);`
		- `document.writeln(...); `
    - GUIDELINE #5 - Avoid the numerous methods which implicitly eval() data passed to it
    - GUIDELINE #6 - Limit the usage of untrusted data to only right side operations
    - GUIDELINE #7 - When URL encoding in DOM be aware of character set issues
    - GUIDELINE #8 - Limit access to properties objects when using object[x] accessors
    - GUIDELINE #9 - Run your JavaScript in a ECMAScript 5 canopy or sandbox
    - GUIDELINE #10 - Don’t eval() JSON to convert it to native JavaScript objects
8. Use HTTPOnly cookie flag