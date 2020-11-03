#declaração de classe em julia
type nome_da_classe
    atributo1::int8
    atributo2 #não é obrigatório especificar o tipo

    metodo1::Function
    metodo2 #não é obrigatório especificar que se trata de uma função
  
	#as especificações são feitas dentro do construtor
	
    #construtor
    function nome_da_classe(at1,at2)

        atributo1 = at1
        atributo2 = at2

        self=new() 
        #instância da própria classe, 
        #que obrigatoriamente é feita dentro do construtor

        self.metodo1 = function(parametros) #metodo1 recebe uma função
            #código
        end

        self.metodo2 = function() #metodo2 recebe uma função
            #código
        end #fim da função

        return self 
        # é necessário retornar o objeto criado para que 
        # sejam atribuídos aos métodos suas funções.
        
    end #fim do construtor

end #fim da classe



mutable struct Exemplo
    atributo1::Int8
    atributo2
end #fim da struct

function funcao_exemplo(e::Exemplo)
  if e.atributo1 == 43
    println(e.atributo2)
  end
  e.atributo1=10
  println(e.atributo1)
end

obj1 = Exemplo(43,"Olá Mundo!")
funcao_exemplo(obj1)



struct Exemplo
    atributo1::Int8
    atributo2
end #fim da struct

function funcao_exemplo(e::Exemplo)
  if e.atributo1 == 43
    println(e.atributo2)
  end
end

obj1 = Exemplo(43,"Olá Mundo!")
funcao_exemplo(obj1)
