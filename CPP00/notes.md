Scope Resolution Operator (::)

Element,Common Convention 1 (Recommended),Common Convention 2 (Prefix),Example
Classes,UpperCamelCase,UpperCamelCase,"PhoneBook, Contact "
Public Functions,camelCase,camelCase,"setFirstName, getLastName"
Local Variables / Arguments,camelCase,snake_case,std::string name
Private Members,_prefix (underscore),m_prefix (member),_firstName or m_firstName

Why std::getline and not std::cin >>?
In C++, std::cin >> input; stops reading at the first whitespace (space, tab, or newline). If a user enters "Jean Luc", std::cin would only take "Jean". std::getline(std::cin, input) reads the entire line including spaces, which is what we need for names and secrets.