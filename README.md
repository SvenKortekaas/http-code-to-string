# http-code-to-string | [![Build Status](https://travis-ci.org/SvenKortekaas/http-code-to-string.svg?branch=master)](https://travis-ci.org/SvenKortekaas/http-code-to-string) [![Code Climate](https://codeclimate.com/github/SvenKortekaas/http-code-to-string/badges/gpa.svg)](https://codeclimate.com/github/SvenKortekaas/http-code-to-string) [![Issue Count](https://codeclimate.com/github/SvenKortekaas/http-code-to-string/badges/issue_count.svg)](https://codeclimate.com/github/SvenKortekaas/http-code-to-string) [![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()
Returning the HTTP code to a full string with explanation in different coding languages.

## How to use
Some examples on how to use the project

### C++
Code example for C++

To support the unofficial HTTP Codes uncomment `//#define UNOFFICIAL_HTTP_CODES` in `http-to-string.hpp`

```CPP
// Include the header
#include http-to-string.hpp

...

// Use it in your code
cout << "[200] " << HTTPToString::httpCode(200)     << endl;
cout << "200: "  << HTTPToString::httpCodeFull(200) << endl;
```

## License

Under [MIT License](http://opensource.org/licenses/mit-license.php)
