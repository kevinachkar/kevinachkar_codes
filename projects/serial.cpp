#include <asio.hpp>
#include <iostream>

int main() {
    asio::io_context io;
    asio::serial_port port(io, "COM5");

    port.set_option(asio::serial_port_base::baud_rate(9600));

    int value = 1234;

    asio::write(port, asio::buffer(&value, sizeof(value)));
}