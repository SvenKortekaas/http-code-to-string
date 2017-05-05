# http-code-to-string | [![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()
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
