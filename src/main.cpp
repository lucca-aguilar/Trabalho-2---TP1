#include <iostream>
#include "interfaces.hpp"
#include "controladores.hpp"
#include "servicos.hpp"

int main() {
    // instancia servicos
    MSC* msc = new MSC();
    MSA* msa = new MSA(msc); 
    MSI* msi = new MSI();

    // instancia controladores
    MAA* maa = new MAA();
    MAC* mac = new MAC();
    MAI* mai = new MAI();
    MAMenu* mainController = new MAMenu();

    // conecta controladores aos servicos
    maa->setAuthenticationService(msa);
    mac->setAccountService(msc);
    mai->setInvestmentService(msi);

    // conecta o controlador principal aos outros controladores
    mainController->setControlers(maa, mac, mai);

    // inicia a aplicacao
    mainController->execute();

    // libera memoria
    delete msc;
    delete msa;
    delete msi;
    delete maa;
    delete mac;
    delete mai;
    delete mainController;

    return 0;
}