#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"

#include <stdexcept>

using namespace std;

// -------------------------------------------------------------------------------------------
// Declara��o adiantada (forward declaration)

class ILNAutenticacao;

// -------------------------------------------------------------------------------------------
// Declara��o de interface para servi�o de autentica��o provido pela camada de apresenta��o.

class IUAutenticacao {
public:

    virtual bool autenticar(Matricula*) = 0                        // M�todo por meio do qual � solicitado servi�o.
    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;      // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.
    virtual ~IUAutenticacao(){}                                     // M�todo destrutor virtual.
};

// -------------------------------------------------------------------------------------------
// Declara��o de interface para servi�o de autentica��o provido pela camada de servi�o.

class ILNAutenticacao {
public:
    virtual bool autenticar(const Matricula&, const Senha&) = 0;    // M�todo por meio do qual � solicitado servi�o.
    virtual ~ILNAutenticacao(){}                                    // M�todo destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
