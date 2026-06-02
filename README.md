![Foto Esquematico arduino e sensor IR](https://github.com/Victor-Jorge/aprendendo-sensor-ir/blob/main/imagens/Esquema_arduino_sensor_IR.png)

LINK DO PROJETO NO TINKERCAD: https://www.tinkercad.com/things/8JBgGh1vj1C/editel

# 📡 Sensor Infravermelho com Arduino

Projeto de controle de LED via controle remoto infravermelho utilizando a biblioteca **IRremote** e Arduino.

---

## 🧠 Entendendo os dados do sensor IR

Quando você pressiona um botão no controle remoto, o sensor captura uma série de informações. No **Serial Monitor** você verá algo assim:

```
Protocolo : NEC
Raw (HEX) : 0xF20DBF00
Endereço  : 0x0
Comando   : 0xD
```

Veja abaixo o que cada campo significa:

---

### 📡 Protocolo: `NEC`

É o **idioma** que o controle e o sensor usam para se comunicar.

> Assim como existem idiomas diferentes (português, inglês, espanhol), existem protocolos diferentes: **NEC, SONY, Samsung**, etc. Se o controle fala NEC e o sensor entende NEC, a comunicação funciona. É o "combinado" de como os dados serão enviados.

Protocolos mais comuns:

| Protocolo | Fabricantes típicos |
|-----------|-------------------|
| NEC       | LG, Samsung, genéricos |
| SONY      | Sony              |
| RC5/RC6   | Philips           |
| Samsung32 | Samsung           |

---

### 🔢 Raw (HEX): `0xF20DBF00`

É a **mensagem completa**, do jeito que saiu do controle — sem nenhum filtro.

> O `0x` só significa *"o que vem depois é um número em hexadecimal"* (uma forma de escrever números usando letras e algarismos). Pense como o **envelope fechado** da carta, contendo tudo: remetente, destinatário e mensagem.

---

### 🏠 Endereço: `0x0`

É o **destinatário** — para qual aparelho a mensagem é enviada.

> Se você tem uma TV e um ar-condicionado na mesma sala, cada um tem um endereço diferente. Assim o sinal sabe para quem vai. O endereço é o "nome da casa" do seu dispositivo.

---

### 🔘 Comando: `0xD`

Esse é o **mais importante** para o seu código — é qual botão foi pressionado.

> É o conteúdo da carta, a ordem em si: *"aumenta volume"*, *"liga/desliga"*, *"muda canal"*. Cada botão do controle tem um comando diferente.

No código, é exatamente esse valor que você compara:

```cpp
if (comando == 0xD) {   // se este botão for pressionado
    estadoLed = !estadoLed;
}
```

---

### 🗺️ Resumo visual

```
Controle aperta botão
        │
        ▼
[ Protocolo: NEC      ] ← idioma usado
[ Raw: 0xF20DBF00     ] ← mensagem completa
        │
        ├──► [ Endereço: 0x0 ] ← para qual aparelho
        └──► [ Comando:  0xD ] ← qual botão foi apertado ✅ ← use este
```

> 💡 **Dica:** No seu código, você só precisa do **Comando**. Os outros campos são informações extras que ajudam a entender e depurar o que está acontecendo.

---

## 🔍 Como descobrir o código do seu controle

1. Faça upload do código no Arduino
2. Abra o **Serial Monitor** (9600 baud)
3. Pressione cada botão do controle **uma vez**
4. Anote o valor de **`Comando`** que aparecer
5. Use esse valor no seu `if` ou `switch`

```cpp
// Exemplo após mapear os botões:
switch (comando) {
  case 0xD:   toggleLed();     break;  // botão OK
  case 0x15:  aumentarVolume(); break; // botão VOL+
  case 0x09:  diminuirVolume(); break; // botão VOL-
}
```

---

## 🛠️ Dependências

- [Arduino IDE](https://www.arduino.cc/en/software)
- Biblioteca [IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)
- Arduino Uno (ou compatível)
- Sensor IR (ex: VS1838B)
- Controle remoto infravermelho

---

## 📦 Instalação da biblioteca

No Arduino IDE:

```
Sketch → Incluir Biblioteca → Gerenciar Bibliotecas → pesquise "IRremote"
```

---

## 📄 Licença

MIT
