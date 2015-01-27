#include "NetworkComunicator.h"
#include "CommandChannel.h"
#include "TcpServer.h"


void NetworkComunicator::Initialize()
{
    int port = 999;
    int ipAddress = 0;
    IComunicationChannel* rxChannel = new CommandChannel();
    IComunicationChannel* txChannel = new CommandChannel();
    this->m_serverThread = new std::thread([=] {
        TcpServer server(ipAddress, port, rxChannel, txChannel);
        server.Run();});

    this->m_serverThread->detach();
}