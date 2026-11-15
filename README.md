# Solucoes-Renovaveis-CitizenAssistAI

#  Citizen Assist AI — Soluções em Energias Renováveis e Sustentáveis (SERS)

##  Integrantes do Grupo
* **Maria Eduarda Rocha Benjamim** — RM: XXXXXX
* **No** — RM: XXXXXX
* **No** — RM: XXXXXX

---

## 1. Contexto, Público-Alvo e Problema Energético
* **Público-Alvo:** Pessoas da **Terceira Idade** (residências de 1 a 2 moradores).
* **Necessidade Energética:** Idosos costumam passar mais tempo em casa, possuem orçamento fixo (aposentadoria) e enfrentam dificuldades com termos técnicos na conta de luz, o que dificulta identificar aparelhos que geram desperdício ou avaliar alternativas sustentáveis.
* **Como o Citizen Assist AI Ajuda:** O assistente traduz dados complexos de consumo energético em orientações claras, acolhedoras e práticas sobre economia de energia e uso de fontes renováveis, apoiado por um protótipo visual tipo semáforo.

---

##  2. Análise de Consumo Energético
* **Fonte dos Dados:** Dataset público *Household Energy Consumption* (Kaggle — 90.000 registros diários de 2025).
* **Recorte Analisado:** Foram filtrados **30.437 registros** de residências com **1 a 2 moradores** (`Household_Size <= 2`), representando o perfil da terceira idade.
* **Unidades e Premissas:**
  * Consumo de energia medido em quilowatt-hora (**kWh**) e temperatura em graus Celsius (**°C**).
  * Período de referência mensal adotado: **30 dias**.
  * Tarifa média residencial utilizada como premissa: **R$ 0,85 / kWh** (Fonte: ANEEL).
  * Fator médio de emissão de carbono do Sistema Interligado Nacional: **0,085 kg CO₂ / kWh** (Fonte: MCTI).

### Principais Descobertas da Análise (Google Colab)
* **Consumo Médio Diário:** `4,76 kWh/dia` (estimativa de **`142,65 kWh/mês`** ou **`R$ 121,25/mês`**).
* **Gasto no Horário de Pico:** Média de `1,95 kWh/dia`, representando **`41,0%` de todo o consumo diário** concentrado no horário crítico da rede.
* **Influência Climática:** Residências com ar-condicionado (`Has_AC = Yes`) e dias com temperaturas mais elevadas apresentam saltos expressivos no consumo diário.

---

##  3. Comparação de Alternativas Energéticas (Base Mensal)
Para atender à mesma necessidade energética mensal (`142,65 kWh/mês`), foram comparadas duas alternativas (incluindo uma **fonte renovável**):

| Critério Avaliado | Cenário Atual (Sem Mudanças) | Alternativa 1: Eficiência Energética | Alternativa 2: Energia Solar (Renovável) |
| :--- | :---: | :---: | :---: |
| **Descrição** | Manutenção dos hábitos atuais | Monitoramento visual + redução de uso no horário de pico e ajuste de climatização (~18%) | Sistema solar fotovoltaico residencial ou energia solar compartilhada (~85% de suprimento) |
| **Consumo da Rede** | `142,65 kWh/mês` | `116,98 kWh/mês` | `21,40 kWh/mês` |
| **Conta de Luz Estimada** | `R$ 121,25/mês` | `R$ 99,43/mês` | `R$ 18,19/mês` |
| **Economia Mensal** | `R$ 0,00` | **`R$ 21,83/mês`** | **`R$ 103,07/mês`** |
| **Investimento Inicial** | `R$ 0,00` | `R$ 150,00` (lâmpadas LED / monitoramento) | `R$ 9.500,00` (sistema próprio) ou `R$ 0,00` (assinatura compartilhada) |
| **Tempo de Retorno (Payback)** | — | **`~6,9 meses`** | **`~92,2 meses`** (ou imediato via assinatura) |
| **CO₂ Evitado** | `0,00 kg/mês` | `2,18 kg/mês` | **`10,31 kg/mês`** |

### Justificativa de Viabilidade e Impactos
* **Eficiência Energética:** Possui custo inicial muito baixo e retorno rápido (menos de 7 meses), sendo ideal para idosos que precisam aliviar o orçamento imediatamente sem realizar obras. Sua limitação é não gerar energia própria.
* **Energia Solar (Renovável):** Reduz em até 85% a dependência da rede elétrica e evita mais de 10 kg de CO₂ por mês. Embora exija alto investimento inicial para instalação própria, planos de **energia solar compartilhada por assinatura** eliminam a necessidade de obras no telhado.

---

##  4. Integração ao Citizen Assist AI e Protótipo Visual
* **Módulo Inteligente (`citizen_assist_energia`):** Os cálculos validados no Google Colab foram incorporados diretamente à função do assistente, que classifica o consumo do usuário e entrega recomendações personalizadas em linguagem simples.
* **Protótipo Visual (Tinkercad / Arduino):** Desenvolvemos um monitor residencial simulado com Arduino Uno, display LCD 16x2 e semáforo de LEDs para facilitar a leitura rápida pelo idoso:
  *  **LED Verde (`<= 30%`):** Consumo baixo e equilibrado.
  *  **LED Amarelo (`31% a 70%`):** Atenção ao consumo.
  *  **LED Vermelho (`> 70%`):** Consumo elevado — alerta imediato para economizar.
* **Link do Protótipo:** [Inserir link do Tinkercad aqui]

---

## 🧪 5. Testes com Usuários e Ajustes Realizados
Foram realizados testes de compreensão e utilidade das orientações geradas pelo assistente com participantes representando o público da terceira idade. Nenhum dado pessoal sensível foi exposto.

| Participante | Situação Testada | Comentário Recebido | Ajuste Realizado |
| :--- | :--- | :--- | :--- |
| **Participante 1** *(Perfil: 68 anos)* | Consulta sobre economia sem saber o consumo em kWh (`duvida="economia"`). | *[Preencher com o comentário real do teste]* | *[Ex: Destacado o valor em Reais (R$) logo no início da frase]* |
| **Participante 2** *(Perfil: 72 anos)* | Consulta sobre energia solar em casa com ar-condicionado (`duvida="solar"`). | *[Preencher com o comentário real do teste]* | *[Ex: Explicado que energia solar compartilhada não exige obra]* |
| **Participante 3** *(Perfil: 65 anos)* | Interpretação do alerta visual de consumo moderado/alto (`duvida="geral"`). | *[Preencher com o comentário real do teste]* | *[Ex: Mantida a relação direta entre as cores do semáforo e o texto]* |

---

##  6. Limitações e Condições das Estimativas
* Os valores financeiros e ambientais apresentados pelo assistente são **estimativas** e não representam economia garantida.
* O consumo real varia conforme o clima local, bandeiras tarifárias vigentes, eficiência dos eletrodomésticos e hábitos de cada morador.
* O dataset utilizado serve como referência estatística de comportamento residencial doméstico.

---

## 7. Como Executar o Projeto
1. Abra o arquivo `analise_energia_sers.ipynb` no **Google Colab**.
2. Faça o upload do dataset `household_energy_consumption.csv` na aba de arquivos do Colab.
3. Execute as células sequencialmente para gerar as estatísticas, os gráficos, a tabela comparativa e simular o atendimento do **Citizen Assist AI**.
4. Para testar o circuito visual, abra o código `monitor_energia.ino` no **Tinkercad Circuits** e inicie a simulação.

---

## 8. Referências
* **Dataset:** *Household Energy Consumption* — Kaggle. Disponível em: https://kaggle.com
* **Tarifas de Energia:** Agência Nacional de Energia Elétrica (ANEEL) — Ranking de Tarifas Residenciais.
* **Fator de Emissão de CO₂:** Ministério da Ciência, Tecnologia e Inovação (MCTI) — Fatores de Emissão do Sistema Interligado Nacional (SIN).
