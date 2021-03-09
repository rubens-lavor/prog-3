compilador online: https://repl.it/languages/julia


#Exemplo Classe, métodos, objeto
 
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


# construtores

struct Exemplo1
	atributo1::Int
	atributo2::Int
end

struct Exemplo2
	atributo1::Int
	atributo2::Int
	Exemplo2(atributo1,atributo2) = new(atributo1,atributo2)

#----------------------------------------------------------------

struct Exemplo
	x::Real
	y::Real
	Exemplo(x,y) = x > y?("Out of order") : new(x,y)
end

#----------------------------------------------------------------

struct Exemplo1
	atributo1
	atributo2
end

Exemplo(x) = Exemplo(x,x)

-#------------------------------------------------------------------

struct Exemplo1{T} 
	atributo1::T
	atributo2::T
end

function template(a::Exemplo,b::Exemplo)
	a.atributo1 + b.atributo1
end

a =  Exemplo(5.6, 7.6)
b = Exemplo (4.8,9.5)

#----------------------------------------------------------------------

struct Exemplo{T} 
	atributo1::T
	atributo2::T
end




#composição e agragação
#--------------------------------------------

x = (sqrt ∘ +)(3, 6)

exemplo = map(first ∘ reverse ∘ uppercase, split("you can compose functions like this"))

exemplo = 1:10 |> sum |> sqrt

exemplo2 = (sqrt ∘ sum)(1:10)

struct Data
    dia::Int
     mes::Int
     ano::Int
end

d = Data (14,2,1996)
vetor = [10 ,20 ,30 ,40 ,50]

i = 2
vetor2 =[2* i ,5 ,3* i ]


#-------------------------------------------


#exemplo de sobrecarga de operadores#
function Base.:+()
  println("Sobrecarga do Operador +")
end

let x = 1
   if x == 1
      +()
   end
end

#-------------------------#
#Exemplo operadores sao funcoes#
println(1+2+3)

println(+(1,2,3))

f = +
println(f(1,2,3))

#-------------------------#
#exemplo polimorfismo por sobrecarga#
function soma( f1 :: Float64 , f2 :: Float64 )
  f1 + f2
end
function soma( i1 :: Int64 , i2 :: Int64 )
  i1 + i2
end
println(soma(2.1,3.1))
println(soma(1,2))

#-------------------------#
#exemplo polimorfismo parametrico#
function parametrico( x :: Any )
  x
end
struct Point
  x :: Int
  y :: Int
end
p = Point(1,2)

println(parametrico(p))
println(parametrico(21))
println(parametrico(13.7))

