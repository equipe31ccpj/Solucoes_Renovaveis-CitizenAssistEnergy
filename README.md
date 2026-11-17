# Solucoes-Renovaveis-CitizenTech

# Citizen Assist Energy — Soluções em Energias Renováveis e Sustentáveis (SERS)

> Módulo de análise de consumo energético, comparação de alternativas sustentáveis e orientação inteligente voltado para a **Terceira Idade**, integrado ao projeto **Citizen Assist Energy**.

---

## Integrantes do Grupo
* **Maria Eduarda Rocha Benjamim** — RM: `570554`
* **Pedro Henrique Neves** — RM: `571382`
* **Akin Alexandre Mendes Martins** — RM: `572773`

---

## Links do Projeto
* **Notebook de Análise (Google Colab):** `https://colab.research.google.com/drive/1-OkzWYJNV690trZIeCEoc5e9_gNxFoti?usp=sharing`
* **Protótipo Visual:** `https://www.tinkercad.com/things/dxc7xNIZYw0-copy-of-prototipo-smart-energy?sharecode=3VK21pKX52YYHgpRcTZEmoF4Xtsc2W1A8_gRIlsgOXg`

---

## 1. Contexto e Público-Alvo
* **Público-Alvo:** Pessoas da terceira idade (residências de 1 a 2 moradores).
* **Necessidade Energética:** Idosos passam mais tempo em casa, o que torna o orçamento doméstico sensível a variações na conta de luz — especialmente em dias quentes com uso de aparelhos de alta potência como ar-condicionado e durante o horário de pico (18h às 21h). Além disso, termos técnicos como *kWh* e *potência* costumam dificultar o controle do gasto mensal.
* **Como a Solução Contribui:** O **Citizen Assist AI** traduz dados técnicos de consumo em alertas visuais simples (integrados ao conceito de semáforo Verde/Amarelo/Vermelho do protótipo Arduino/Tinkercad) e recomendações financeiras e ambientais acessíveis.

---

## 2. Dados Utilizados e Premissas de Cálculo
* **Dataset Principal:** *Household Energy Consumption (2025)* — Base pública do Kaggle com 90.000 registros diários.
* **Recorte Analisado:** 30.437 registros filtrados para residências de **1 a 2 moradores**.
* **Unidades e Período de Referência:** Consumo medido em **kWh** (quilowatt-hora), projetado para um ciclo mensal padrão de **30 dias**.
* **Premissas Oficiais e Estimadas:**
  * **Tarifa Residencial Média (Fonte Real):** **R$ 0,85 / kWh** (referência ANEEL).
  * **Fator de Emissão de CO₂ (Fonte Real):** **0,085 kg CO₂ / kWh** no Sistema Interligado Nacional (referência MCTI).
  * **Dados Estimados pela Equipe:** Redução de **18%** com eficiência energética (investimento estimado de **R$ 150,00** em monitoramento/LEDs) e suprimento de **85%** via energia solar (investimento estimado de **R$ 9.500,00** para sistema residencial de pequeno porte).

### Conceito Físico Aplicado: Potência vs. Energia
Para orientar o uso de aparelhos, aplicamos a relação $E = P \times \Delta t$:
* Um ar-condicionado de **1.200 W (1,2 kW)** ligado por **2 horas/dia** consome **2,4 kWh/dia** (**72 kWh/mês**), representando metade do consumo médio mensal do perfil analisado.

---

## 3. Comparação de Alternativas (Base Mensal: 142,65 kWh/mês)

| Cenário | Consumo da Rede (kWh/mês) | Conta de Luz (R$/mês) | Economia Mensal (R$) | Investimento Inicial (R$) | Retorno / Payback (Meses) | CO₂ Evitado (kg/mês) |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| **Atual (Sem Mudanças)** | 142,65 | R$ 121,25 | R$ 0,00 | R$ 0,00 | — | 0,00 kg |
| **Alt 1: Eficiência Energética** | 116,98 | R$ 99,43 | R$ 21,83 | R$ 150,00 | **6,9 meses** | 2,18 kg |
| **Alt 2: Energia Solar (Renovável)** | 21,40 | R$ 18,19 | R$ 103,07 | R$ 9.500,00 | **92,2 meses** | **10,31 kg** |

### Justificativa das Recomendações
* **Eficiência Energética (Curto Prazo / Baixo Custo):** Recomendada como primeira ação imediata. Possui custo quase zero, payback rápido (~7 meses) e evita o uso de aparelhos pesados no horário de pico (que representa **41%** do gasto diário no dataset).
* **Energia Solar Fotovoltaica ou Compartilhada (Médio/Longo Prazo):** Recomendada para residências com consumo moderado a alto (ex.: uso frequente de ar-condicionado). Gera a maior economia mensal (até 85%) e o maior impacto ambiental positivo (**10,31 kg de CO₂ evitados/mês**). Para idosos que não desejam obras no telhado, o assistente sugere planos de **energia solar compartilhada por assinatura**.

---

## 4. Integração ao Citizen Assist AI e Protótipo Tinkercad
* **Módulo em Python (`citizen_assist_energia`):** Incorpora diretamente as variáveis calculadas na análise exploratória para responder dúvidas do usuário sobre economia ou energia solar, classificando o consumo no padrão visual do monitor:
  * **Verde:** Até 180 kWh/mês (Consumo baixo e equilibrado).
  * **Amarelo:** De 181 a 350 kWh/mês (Atenção: consumo moderado).
  * **Vermelho:** Acima de 350 kWh/mês (Alerta: consumo elevado).
* **Protótipo Arduino (Tinkercad):** Simula o indicador luminoso (LEDs Verde, Amarelo e Vermelho) e display informativo para facilitar a leitura visual do gasto energético pela terceira idade.

### Condições e Limitações das Estimativas
* Os valores financeiros e de economia são **estimativas educacionais** baseadas na tarifa média nacional (R$ 0,85/kWh) e não representam garantia de faturamento.
* O resultado real varia conforme a distribuidora local, bandeiras tarifárias vigentes, clima da região e eficiência dos eletrodomésticos da residência.

---

## 5. Como Executar o Código
1. Baixe o arquivo do notebook (`Citizen_Assist_Energy.ipynb`) e o dataset (`household_energy_consumption.csv`) deste repositório (ou abra diretamente no Google Colab).
2. Certifique-se de que as bibliotecas `pandas`, `numpy`, `matplotlib` e `seaborn` estejam instaladas.
3. Execute as células sequencialmente para gerar as estatísticas, os gráficos e testar a função interativa `citizen_assist_energia()`.

---

## 6. Registro de Testes com Usuários
Para validar a clareza das orientações sem expor dados pessoais, foram realizados testes de compreensão com representantes do público-alvo:

| Perfil Testado | Situação Avaliada | Feedback Recebido | Ajuste Aplicado |
| :--- | :--- | :--- | :--- |
| **Usuário A** (67 anos, mora sozinho) | Consulta de economia sem saber o consumo exato da conta. | *"Achei bom ter uma média pronta, mas não entendia o valor apenas em kWh."* | Exibição imediata do valor equivalente em **Reais (R$/mês)** junto ao kWh. |
| **Usuário B** (72 anos, casal com AC) | Simulação de consumo alto (420 kWh/mês). | *"A cor vermelha ajudou a entender o alerta e a dica de limpar o filtro é simples."* | Destaque no status do semáforo e priorização de dicas sem custo inicial. |
| **Usuário C** (64 anos, aposentado) | Consulta específica sobre energia solar. | *"Achava que precisava fazer obra no telhado para usar energia solar."* | Inclusão da alternativa de **energia solar compartilhada (assinatura)**. |

---

## 7. Referências
* **Kaggle — Household Energy Consumption Dataset (2025):** Base de dados de consumo residencial diário.
* **ANEEL (Agência Nacional de Energia Elétrica):** Ranking de Tarifas Residenciais (referência de R$ 0,85/kWh).
* **MCTI (Ministério da Ciência, Tecnologia e Inovação):** Fatores de Emissão de CO₂ do Sistema Interligado Nacional (0,085 kg CO₂/kWh).
* **PROCEL / Eletrobras:** Guias de Eficiência Energética e Etiquetagem de Equipamentos Residenciais.

