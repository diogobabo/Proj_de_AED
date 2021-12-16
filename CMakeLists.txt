cmake_minimum_required(VERSION 3.17)
project(Proj_de_AED)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proj_de_AED main.cpp Airplane.cpp Airplane.h Flight.cpp Flight.h Maintenance.cpp Maintenance.h Passenger.cpp Passenger.h AirplaneCompany.cpp AirplaneCompany.h Interface.cpp Interface.h Airport.h Airport.cpp Transport.h Transport.cpp bst.h Ticket.h Ticket.cpp)