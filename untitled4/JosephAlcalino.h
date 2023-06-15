
class JosephAlcalino{
private:
    float salud;
    float armadura;
    float ataque;
    int nivel;

public:
    JosephAlcalino(float salud, float armadura, float ataque, int nivel);
    JosephAlcalino();
    ~JosephAlcalino();
    int getNivel();
    float getSalud();
    float getArmadura();
    float getAtaque();
    void setNivel(int nivel);
    void setSalud(float salud);
    void setArmadura(float armadura);
    void setAtaque(float ataque);
};

