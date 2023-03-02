#include <SFML/Network.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

const sf::IpAddress SERVER_IP = IpAddress::getLocalAddress();
const int SERVER_PORT = 55000;

int main() {

    sf::TcpSocket socket;
    sf::TcpSocket socket_1;
    sf::TcpSocket socket_2;

    std::string text;
    sf::Packet in_pack;
    sf::Packet out_pack;
    size_t size;

    sf::TcpListener listener;
    listener.listen(SERVER_PORT);

    std::cout << "Server is running on ip : " << SERVER_IP << "/" << SERVER_PORT << std::endl;


    std::string host;
    string message;


    while (true) {
        listener.accept(socket);
        // Receiving ip addres of clients
        socket.receive(in_pack);
        in_pack >> message;
        std::cout << "Some one connected with ip : " << socket.getRemoteAddress() << "/" << socket.getRemotePort() << endl;
        cout << "Message from [" << socket.getRemoteAddress() << "/" << socket.getRemotePort() << "]:" << message << endl;
        

        out_pack << "Done";
        socket.send(out_pack);

        out_pack.clear();
        in_pack.clear();
        
    }


    system("pause");
    return 0;
}