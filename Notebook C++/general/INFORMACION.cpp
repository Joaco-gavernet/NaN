
                 DATA STRUCTURE - C++


---------------------- VECTOR -----------------------

vector <ll> v; //DECLARACION DEL VECTOR, TAMANO 0.

vector <ll> v(n); //DECLARACION DEL VECTOR DE TAMANO N

v.push_back(n); //PUSHEA N AL FINAL DEL VECTOR, O(1)

sort(v.begin(),v.end()); //ORDENA EL VECTOR, O(n.logn)

v.pop_back(); //ELIMINA EL ULTIMO VALOR DEL VECTOR, O(1);

v.size(); //RETORNA EL TAMANO DEL VECTOR

v.clear(); //BORRA TODO EL VECTOR

v.resize(n); //ESTABLECEMOS EL TAMANO DEL VECTOR A TAMANO N

vector<pair<ll,ll>> v; //VECTOR DE PAIR

v.push_back(make_pair(a,b)); //PUSHEA EL PAR (A,B).

v[i].first; //RETORNA EL PRIMER VALOR DEL PAIR

v[i].second; //RETORNA EL SEGUNDO VALOR DEL PAIR

for(auto u : v) //RECORRE TODOS LOS VALORES DEL VECTOR

BUENO PARA STACKEAR COSAS, PARA USARLO COMO LISTA DE ADYACENCIAS
EN LOS PROBLEMAS DE GRAFOS, PARA USARLOS COMO ARREGLO.
SI SE ORDENA UN VECTOR DE PAIR, LOS ORDENA DE MENOR A MAYOR SEGUN
EL PRIMER VALOR, Y LUEGO DE MENOR A MAYOR SEGUN EL SEGUNDO.

------------------------------------------------------


----------------------- SET --------------------------

set <int> s; //DECLARACION DEL SET, EL SET GUARDA LOS ELEMENTOS UNA SOLA
			 //VEZ, Y MIENTRAS LOS VA GUARDANDO, LOS VA ORDENANDO.

multiset <int> s; //DECLARACION DEL MULTISET. EL MULTISET PUEDE GUARDAR
				  //VARIAS COPIAS DEL MISMO NUMERO, Y MIENTRAS LOS VA
				  //GUARDANDO, LOS VA ORDENANDO.

s.insert(n); //INSERTA EL VALOR N EN EL SET, SI YA ESTABA INSERTADO, NO
			 //NO SE MODIFICA NADA. O(logn)

s.erase(n); //ELIMINA EL VALOR N DEL SET, O(log n)

s.size(); //TAMANO DEL SET

s.clear(); //BORRA TODOS LOS ELEMENTOS DEL SET O(s.size())

auto it=s.begin(); //DECLARACION DEL ITERATOR IT PARA EL SET

it=s.find(n); //HALLA LA POSICION DEL VALOR N DENTRO DEL SET, SI NO
			  //CREO QUE RETORNA s.end(); (FINAL DEL SET)

it.lower_bound(n); //HERRAMIENTA FUERTISIMA DEL SET. CON BUSQUENA 
        //BINARIA OBTIENE EL PRIMER VALOR DEL SET QUE ES MAYOR O IGUAL
        //A N, O(logn)

it=upper_bound(n); //HERRAMIENTA TAMBIEN MUY FUERTE, PERO NO LA SUELO 
          //USAR MUCHO, SUELE PODER SER REEMPLAZADA POR EL LOWER_BOUND
          //EN O(logn) DEVUELVE EL PRIMER VALOR MAYOR ESTRICTO QUE
          //N

for(auto it : s) //RECORRE TODOS LOS VALORES DEL SET

// Custom comparators
struct Edge {
	int a, b, w;
};
struct cmp { // Funcion comparadora para el set
	bool operator()(const Edge &x, const Edge &y) const { return x.w < y.w; }
};

int main() {
	int M = 4;
	set<Edge, cmp> v;
	...

// FACIL DE USAR. PUEDE REEMPLAZAR EL PRIORITY QUEUE PERO ES UN POQUITO MAS 
// LENTO. BUENO PARA PROBLEMA QUE CONVIENE IR ORDENANDO EN TIEMPO REAL, 
// EN VEZ DE LEER TODO Y LUEGO ORDENARLO. SE USA MUCHO EN ALGORITMOS PARA 
// GRAFOS COMO DIJKSTRA Y PRIM.


--------------------------------------------------------------

------------------------ QUEUE -------------------------------

queue <int> q; //DECLARACION DEL QUEUE

q.push(n); //PUSHEA AL FINAL DEL QUEUE EL NUMERO N

q.front(); //OBTIENE EL NUMERO QUE SE ENCUENTRA PRIMERO EN LA QUEUE

q.pop() //BORRA EL NUMERO QUE SE ENCUENTRA PRIMERO EN EL QUEUE

--------------------------------------------------------------

--------------------- PRIORITY QUEUE -------------------------

prority_queue <int> pq; //DECLARACION DEL PRIORITY_QUEUE. A MEDIDA QUE
						//VAMOS INSERTANDO VALORES, LOS VA ORDENANDO EN
						//ORDEN CRECIENTE.

priority_queue<int, vector<int>, greater<int>> pq; // PRIORITY_QUEUE DE MINIMO

pq.push(n); //INSERTA EL VALOR N EN EL LUGAR QUE CORRESPONDE. O(log n)

pq.top(); //OBTIENE EL VALOR QUE SE ENCUENTRA PRIMERO EN LA PQ.

pq.pop(); //ELIMINA EL ELEMENTO QUE SE ENCUENTRA PRIMERO EN LA PQ.
