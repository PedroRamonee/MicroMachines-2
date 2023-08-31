#include "player.hpp"

Player::Player() {
    /*
    Construção da classe Player:

        - Textura definida
        - Sprite definido, posicionado, escaldo e com origem definida
        - Define a posição X e Y como a posição inicial do carro
        - Inicializa a rotação inicial do carro, a posição (Vector2f), e a
    rotação atual do carro
        - Inicializa a velocidade do carro, e as variáveis de controle
    */
    tex.loadFromFile("assets/Audi.png");

    carro.setTexture(tex);
    carro.setPosition(690.f, 600.f);
    carro.Transformable::scale(0.2f, 0.2);
    carro.setOrigin(Vector2f(50.f, 50.f));

    posX = carro.getPosition().x;
    posY = carro.getPosition().y;

    initialRotate = carro.getRotation();
    initialPos = carro.getPosition();
    actualRotate = carro.getRotation();

    velocidade.x = 0;
    velocidade.y = 0;

    typeRotate = 0;
    repulsion = 1;
    voltas = 0;
    rotate = 0;
    out = false;
}

void Player::setPos(RenderWindow *window) {
    /*
    Operações basicas de movimentação do jogador:

        - Ao pressionar uma tecla define a velocidade e a rotação do carro e
    estabelece o valor da variavel de controle de rotação
        - Define a varivel actualRotate com a rotação atual do carro
        - Altera a posição do carro
        - Se o carro sair da tela define a variavel de controle out como true
    que desencadeia as funções que corrigem a posição do player, caso contrário
    define a o posição do sprite e desenha na tela
    */
    velocidade.x = 0;
    velocidade.y = 0;
    if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocidade.x = 0.15;
        velocidade.y = 0;
        carro.setRotation(initialRotate + 90.f);
        typeRotate = 1;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocidade.x = -0.15;
        velocidade.y = 0;
        carro.setRotation(initialRotate - 90.f);
        typeRotate = 2;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocidade.y = -0.15;
        velocidade.x = 0;
        carro.setRotation(initialRotate);
        typeRotate = 0;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocidade.y = 0.15;
        velocidade.x = 0;
        carro.setRotation(initialRotate + 180.f);
        typeRotate = 3;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        carro.setRotation(initialRotate + 45.f);
        velocidade.x = 0.10;
        velocidade.y = -0.10;
        typeRotate = 4;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        carro.setRotation(initialRotate - 45.f);
        velocidade.x = -0.10;
        velocidade.y = -0.10;
        typeRotate = 5;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        carro.setRotation(initialRotate + 135.f);
        velocidade.x = 0.10;
        velocidade.y = 0.10;
        typeRotate = 6;
    }

    if (Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        carro.setRotation(initialRotate - 135.f);
        velocidade.x = -0.10;
        velocidade.y = 0.10;
        typeRotate = 7;
    }

    actualRotate = carro.getRotation();

    posX += velocidade.x;
    posY += velocidade.y;

    if (Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        cout << "PosX ->" << posX << "\nPosY ->" << posY << endl;
    }

    if (posX + carro.getGlobalBounds().width < 0 ||
        posX - carro.getGlobalBounds().width > 1200 ||
        posY + carro.getGlobalBounds().height < 0 ||
        posY - carro.getGlobalBounds().height > 1200) {
        out = true;
    } else {
        carro.setPosition(posX, posY);
        window->draw(carro);
    }
}

int Player::getRotate() {
    return rotate;
}  // retorna a variavel de controle de rotação
bool Player::getOut() { return out; }  // retorna se o carro saiu ou nao da tela
void Player::setVoltas() {
    voltas++;
}  // aumenta em 1 a contagem de voltas (rotação) do carro
Vector2f Player::getSpeed() {
    return velocidade;
}  // retorna a velocidade do personagem
float Player::getRepulsion() {
    return repulsion;
}  // retorna a repulsão do jogador
float Player::getTypeRotate() {
    return typeRotate;
}  // retorna o tipo de rotação atual do jogador

void Player::outMap() {
    /*
    Realiza as operações necessárias para corrigir o posicionamento do jogador
    caso saia da tela:

        - Define a rotação do sprite
        - aumenta o tanto que o carro rotacionará na proxima vez que a função
    for chamada
        - caso o carro ja tenha girado 360°, define como 0 a proxima rotação do
    sprite
        - se o carro ja tiver girado 3 vezes o carro retorna pra posiçaõ inicial
    e define como false a variavel de controle out

    */
    carro.setRotation(actualRotate + rotate);

    rotate++;

    if (rotate > 360) {
        rotate = 0;
    }
    if (voltas == 3) {
        out = false;
        posX = initialPos.x;
        posY = initialPos.y;
        voltas = 0;
    }
}

void Player::collide() {
    /*
    Realiza as operações necessarias para realizar a colisão do Player:

        - Altera a posição do jogador em relação a rotação atual dele
        - Define a posição do sprite após realziar a operação
    */
    switch (typeRotate) {
        case 0:
            posY += repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 1:
            posX -= repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 2:
            posX += repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 3:
            posY -= repulsion;
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 4:
            posY += (repulsion / 2);
            posX -= (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 5:
            posY += (repulsion / 2);
            posX += (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 6:
            posY -= (repulsion / 2);
            posX -= (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        case 7:
            posY -= (repulsion / 2);
            posX += (repulsion / 2);
            repulsion++;
            if (repulsion > 15) {
                repulsion = 1;
            }
            break;
        default:
            break;
    }

    cout << repulsion << endl;

    cout << "PosX ->" << posX << "\nPosY ->" << posY << endl;

    carro.setPosition(posX, posY);
}
