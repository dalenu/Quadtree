#include <iostream>
#include <string>
#include "Quadtree.cpp"

int main() {

        std::string line;
        Quadtree* tree;
        tree = nullptr;

        while(!std::cin.eof()) {
                getline(std::cin, line);
                int command_length;
                command_length = line.find(" ");
                std::string cmd;
		std::string params;
                cmd = line.substr(0, command_length);

		std::string name;
		double x;
		double y;
		int population;
		int cost;
		int salary;
		std::string dirtemp;
		int dir;
		int mode;		

                if (cmd == "i") {
			params = line.substr(command_length + 1);
			command_length = params.find(";");
			name = params.substr(0, command_length);
			params = params.substr(command_length + 1);
			command_length = params.find(";");
			x = std::stod(params.substr(0, command_length));
			params = params.substr(command_length + 1);
			command_length = params.find(";");
			y = std::stod(params.substr(0, command_length));
			params = params.substr(command_length + 1);
		        command_length = params.find(";");
			population = std::stoi(params.substr(0, command_length));
			params = params.substr(command_length + 1);
			command_length = params.find(";");
			cost = std::stoi(params.substr(0, command_length));
			salary = std::stoi(params.substr(command_length + 1));

			if (tree == nullptr) {
				tree = new Quadtree(name, x, y, population, cost, salary);
				std::cout << "success" << std::endl;
			} else if (tree->insert(name, x, y, population, cost, salary) == 0) {
				std::cout << "success" << std::endl;
			} else {
				std::cout << "failure" << std::endl;
			}	
                } else if (cmd == "s") {
                        std::string params = line.substr(command_length + 1);
			command_length = params.find(";");
			x = std::stod(params.substr(0, command_length));
			y = std::stod(params.substr(command_length + 1));
			if (tree == nullptr) {
                                std::cout << "not found" << std::endl;
                        } else {
                                Quadtree* temp = tree->search(x, y);
                                if (temp == nullptr) {
                                        std::cout << "not found" << std::endl;
                                } else {
                                        std::cout << "found " << temp->name << std::endl;
                                }
                        }	
                } else if (cmd == "q_max") {
                        params = line.substr(command_length + 1);
                        command_length = params.find(";");
                        x = std::stod(params.substr(0, command_length));
                        params = params.substr(command_length + 1);
                        command_length = params.find(";");
                        y = std::stod(params.substr(0, command_length));
                        params = params.substr(command_length + 1);
                        command_length = params.find(";");
                        dirtemp = params.substr(0, command_length);
			params = params.substr(command_length + 1);

			if (dirtemp == "NE") {
				dir = 0;
			} else if (dirtemp == "NW") {
				dir = 1;
			} else if (dirtemp == "SW") {
				dir = 2;
			} else {
				dir = 3;
			}

			if (params == "p") {
                        	mode = 0;
			} else if (params == "r") {
				mode = 1;
			} else {
				mode = 2;
			}

			if (tree == nullptr) {
				std::cout << "failure" << std::endl;
			} else {
				int temp = tree->qmaster(x, y, dir, mode, 0);
				if (temp == -1) {
					std::cout << "failure" << std::endl;
				} else {
					std::cout << "max " << temp << std::endl;
				}
			}
                } else if (cmd == "q_min") {
                        params = line.substr(command_length + 1);
                        command_length = params.find(";");
                        x = std::stod(params.substr(0, command_length));
                        params = params.substr(command_length + 1);
                        command_length = params.find(";");
                        y = std::stod(params.substr(0, command_length));
                        params = params.substr(command_length + 1);
                        command_length = params.find(";");
                        dirtemp = params.substr(0, command_length);
                        params = params.substr(command_length + 1);

                        if (dirtemp == "NE") {
                                dir = 0;
                        } else if (dirtemp == "NW") {
                                dir = 1;
                        } else if (dirtemp == "SW") {
                                dir = 2;
                        } else {
                                dir = 3;
                        }

                        if (params == "p") {
                                mode = 0;
                        } else if (params == "r") {
                                mode = 1;
                        } else {
                                mode = 2;
                        }

                        if (tree == nullptr) {
                                std::cout << "failure" << std::endl;
                        } else {
                                int temp = tree->qmaster(x, y, dir, mode, 1);
                                if (temp == -1) {
                                        std::cout << "failure" << std::endl;
                                } else {
                                        std::cout << "min " << temp << std::endl;
                                }
                        }
                } else if (cmd == "q_total") {
                        params = line.substr(command_length + 1);
                        command_length = params.find(";");
                        x = std::stod(params.substr(0, command_length));
                        params = params.substr(command_length + 1);
                        command_length = params.find(";");
                        y = std::stod(params.substr(0, command_length));
                        params = params.substr(command_length + 1);
                        command_length = params.find(";");
                        dirtemp = params.substr(0, command_length);
                        params = params.substr(command_length + 1);

                        if (dirtemp == "NE") {
                                dir = 0;
                        } else if (dirtemp == "NW") {
                                dir = 1;
                        } else if (dirtemp == "SW") {
                                dir = 2;
                        } else {
                                dir = 3;
                        }

                        if (params == "p") {
                                mode = 0;
                        } else if (params == "r") {
                                mode = 1;
                        } else {
                                mode = 2;
                        }

                        if (tree == nullptr) {
                                std::cout << "failure" << std::endl;
                        } else {
                                int temp = tree->qmaster(x, y, dir, mode, 2);
                                if (temp == -1) {
                                        std::cout << "failure" << std::endl;
                                } else {
                                        std::cout << "total " << temp << std::endl;
                                }
                        }
                } else if (cmd == "print") {
			if (tree != nullptr) {
				tree->print();
				std::cout << std::endl;
			}
		} else if (cmd == "clear") {
			if (tree != nullptr) {
				tree->clear();
				tree = nullptr;
			}
			std::cout << "success" << std::endl;
		} else if (cmd == "size") {
			if (tree != nullptr) {
				std::cout << "tree size " << tree->getsize() << std::endl;
			} else {
				std::cout << "tree size 0" << std::endl;
			}
		}
        }
}
