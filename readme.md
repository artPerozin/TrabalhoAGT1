# 🎬 CINESC – Sistema de Recomendação de Filmes

O **CINESC** é um sistema de recomendação de filmes personalizado, projetado para oferecer sugestões baseadas nas preferências do usuário. Utilizando uma base de dados local, o sistema filtra e apresenta os filmes mais relevantes conforme os critérios informados.

---

## 📌 Sumário

- [📖 Introdução](#📖-introdução)  
- [🚀 Funcionalidades](#🚀-funcionalidades)  
- [🔁 Fluxo do Sistema](#🔁-fluxo-do-sistema)  
  - [1. Acesso Inicial](#1-acesso-inicial)  
  - [2. Coleta de Preferências](#2-coleta-de-preferências)  
  - [3. Processamento das Preferências](#3-processamento-das-preferências)  
    - [3.1 Normalização das Entradas](#31-normalização-das-entradas)  
    - [3.2 Consulta à Base de Dados](#32-consulta-à-base-de-dados)  
    - [3.3 Aplicação de Filtros](#33-aplicação-de-filtros)  
  - [4. Geração da Recomendação](#4-geraçã0-da-recomendação)  
- [📋 Resultado da Recomendação](#📋-resultado-da-recomendação)  
- [🌟 Futuras Expansões](#🌟-futuras-expansões)

---

## 📖 Introdução

O **CINESC** foi criado com o objetivo de proporcionar ao usuário uma experiência única e personalizada na descoberta de novos filmes. Através da coleta de preferências, o sistema aplica filtros inteligentes para recomendar títulos que se alinham aos gostos e critérios definidos.

---

## 🚀 Funcionalidades

- Interface simples para coleta de preferências  
- Filtros por gênero, faixa etária, avaliação mínima e estilo de filme  
- Consulta e filtragem em base de dados local  
- Exibição de até 10 recomendações personalizadas  

---

## 🔁 Fluxo do Sistema

### 1. Acesso Inicial

O usuário acessa o sistema e é recebido com um questionário simples para personalizar sua experiência de recomendação.  
<br>

### 2. Coleta de Preferências

O sistema solicita os seguintes dados:  
<br>

- 🎭 **Gêneros favoritos**: Ação, Drama, Comédia, Terror, etc.  
- 🎂 **Faixa etária**: Para garantir a compatibilidade com a classificação indicativa.  
- ⭐ **Avaliação mínima esperada** *(opcional)*: Ex. somente filmes com nota maior que 4.5.  
- 🎞️ **Estilo de filme** *(opcional)*: Curta, longa, série, clássico, etc.  
- 📅 **Ano de lançamento** *(opcional)*: Ex. somente filmes a partir de 2005.  
<br>

### 3. Processamento das Preferências

#### 3.1 Normalização das Entradas

As informações são padronizadas para evitar erros e duplicidades.  
<br>

#### 3.2 Consulta à Base de Dados

O sistema utiliza uma base local com dados estruturados sobre filmes.  
<br>

#### 3.3 Aplicação de Filtros

Os seguintes filtros são aplicados:

- Gêneros escolhidos  
- Classificação etária  
- Avaliação mínima  
- Estilo e ano de lançamento  
- Ordenação por relevância  

<br>

### 4. Geração da Recomendação

O sistema monta uma **lista de até 10 filmes recomendados**, com base nos filtros definidos e ordenados por relevância.

---

## 📋 Resultado da Recomendação

Cada filme recomendado apresenta:

- 🎬 Nome do filme  
- 🎭 Gênero  
- ⭐ Avaliação  
- 📅 Ano de lançamento  
- 👥 Elenco principal  
- 📝 Mini sinopse  

---

## 🌟 Futuras Expansões

- Integração com bases de dados externas (ex: IMDb, TMDB)  
- Implementação de algoritmos de aprendizado de máquina para recomendações mais inteligentes  
- Salvamento do histórico do usuário para sugestões progressivamente melhores  

---

Sinta-se à vontade para colaborar com este projeto ou sugerir melhorias!  
✨ **Descubra filmes como nunca antes com o CINESC.**

