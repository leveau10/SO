#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

static std::vector<std::string> commandHistory;
static std::vector<pid_t> process;
void process_command(std::string command) {
    // Se for comando interno...
    
    // Se for comando externo
    // if (command == "jobs"){
    //     for(int j = 0; j < back_proc.size(); j++ ){
    //         std::cout << "Processo:"<< back_proc[j] << std::endl;
    //     }
    // }
   

    // * necessário verificar se é para ser executado em background
    /*  Se for caminho relativo, procurar o comando na lista de diretórios
        Se for absoluto verifica se comando existe
    */

    //caminho relativo e processo em background

    std::istringstream iss(command);

    std::string word;
    int count = 0;
    while (iss >> word) {
        ++count;
    }

    
    std::string* tokens = new std::string[count];

    iss.clear();
    iss.seekg(0, std::ios::beg);

    int index = 0;
    while (iss >> word) {
        tokens[index++] = word;
    }

    bool isBackground = false;  //checa se é para rodar em background;
    if(tokens[count-1] == "&"){
        std::cout << "& detectado" << std::endl;
        isBackground = true;
    }

    
    // for (int i = 0; i < count; ++i) {
    //     std::cout << tokens[i] << std::endl;
    // }

    std::string absolute_path = "/bin/" + tokens[0] ; 


    if (tokens[0] == "exit"){
        exit(0);
    }
    else if (tokens[0] == "pwd"){
        commandHistory.push_back(command);
        std::cout << get_current_dir_name() <<" tá aqui po"<< std::endl;
    }
    else if(tokens[0] == "history"){
        if(tokens[1] == "-c"){
            commandHistory.clear();
            std::cout << "Histórico apagado"<< std::endl;
        }else{
            for(int i = 0 ; i<commandHistory.size() ; i++){
                std::cout << i+1 << ": "  << commandHistory[i] << std::endl;
            }
            commandHistory.push_back(command);
        }
    }
    
    
    //contar a quantidade de parametros na string e passar a primeira string

    else if(access(absolute_path.c_str(), F_OK) == 0) { // Arquivo existe no diretório
        if (access(absolute_path.c_str(), X_OK) == 0) { // Arquivo é executável
            commandHistory.push_back(command);
            pid_t pid = fork();
            if (pid < 0){ // Erro
                std::cout << "Erro de execução!" << std::endl;
                return; 
            } else if (pid == 0){ //processo filho
                //contar quantidade de parametros e instanciar o ponteiro abaixo o [2]
                char * argv[count+1] = {(char *)tokens[0].c_str(),nullptr};
                for (int i = 1; i < count; ++i) {
                    argv[i] = (char *)tokens[i].c_str();
                }
                argv[count] = nullptr;
                execve(absolute_path.c_str(), argv, NULL);
            } else { // Processo pai
                // if(isBackground){
                //     std::cout << "Process " << pid << " running in background." << std::endl;
                //     /* Deve adicionar processo filho na lista (std::vector) de processos em execução para gerenciar background. */
                // }else{
                    waitpid(pid, nullptr, 0); 
                    /* Processo pai espera processo filho terminar. */
                // }
            }
        } else { // Arquivo não é executável
            std::cout << "permission denied: " << command << std::endl;
        }
    } else { // Arquivo não existe
        std::cout << "Command not found: " << command << std::endl;
    }
}

int main() {
    
    while (true) {
        std::cout << "$> ";
        std::string command;
        getline(std::cin, command);
        process_command(command);
    }
    return 0;
}
