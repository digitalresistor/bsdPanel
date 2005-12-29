#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Math.h"
#include "Net_Address.h"
#include "Net_DomainName.h"
#include "Net_DomainNameException.h"

namespace bsdPanel
{
    namespace Net
    {
        DomainName::DomainName() : Address()
        {
            name = new std::string("example.net");
            
            if ( !isValid() )
                throw DomainNameException(DomainNameException::INVALID_ADDRESS);
        }
        
        DomainName::DomainName(const DomainName & rhs) : Address(rhs.getDelim())
        {
            delim = rhs.getDelim();
            name = new std::string(rhs.getName());
            
            if ( !isValid() )
                throw DomainNameException(DomainNameException::INVALID_ADDRESS);
        }
        
        DomainName::~DomainName()
        {
            delete name;
        }
        
        bool isValid() const
        {
            bool check = false;
            std::vector<std::string> * parts = split_string(name, delim);
            
            return check;
        }
        
        void load_domain_codes()
        {
            domain_code = new std::vector<std::string>;
            
            // Ok, we need to open the file with the codes and
            // store them into the domainCode vector
            std::ifstream codes;
            codes.open("Net_DomainNameCodes.dat");
            
            std::string code;
            
            if (codes.is_open()) {
                // file is open, we can now read the contents into the vector
                do { 
                    std::getline(codes, code);
                    domain_code->push_back(code);
                } while (!codes.eof());

            } else {
                // Error reading file, we need to decide how to deal with this
                // Throw an exception :P
            }
            
            codes.close();
        }
    }
}