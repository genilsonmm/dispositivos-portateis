<template>
  <ion-page>

    <HeaderComponent :title="'Início'" />

    <ion-content :fullscreen="true">
      <ion-header collapse="condense">
        <ion-toolbar>
          <ion-title size="large">Blank</ion-title>
        </ion-toolbar>
      </ion-header>

      <div id="container">

        <ion-card>
          <ion-card-header>
            <ion-card-title>Cadastro</ion-card-title>
          </ion-card-header>

          <ion-card-content>
            <ion-input v-model="name" placeholder="Digite seu nome"></ion-input>
            <ion-button @click="register" color="success">Cadastrar</ion-button>
          </ion-card-content>
        </ion-card>

        <ion-list>
          <ion-item v-for="(contato, index) in contatos" :key="index">
            <ion-label>{{ contato.nome }}</ion-label>
          </ion-item>
        </ion-list>

        <strong>ionic serve --address 0.0.0.0</strong>
        <p>Start with Ionic <a target="_blank" rel="noopener noreferrer"
            href="https://ionicframework.com/docs/components">UI Components</a></p>
      </div>
    </ion-content>
  </ion-page>
</template>

<script setup lang="ts">
import HeaderComponent from '@/components/HeaderComponent.vue';
import {
  IonButton, IonCard, IonCardContent, IonCardHeader, IonCardSubtitle, IonCardTitle,
  IonContent,
  IonInput,
  IonList, IonItem, IonLabel,
  IonHeader, IonPage, IonTitle, IonToolbar
} from '@ionic/vue';

import { ref } from 'vue';

const name = ref('');
const contatos = ref([
  { nome: 'Ana', telefone: '99999-9999' },
  { nome: 'Bruno', telefone: '88888-8888' },
  { nome: 'Carlos', telefone: '77777-7777' }
]);

function register() {
  contatos.value.push({ nome: name.value, telefone: '' });
  name.value = '';
}

</script>

<style scoped>
#container {
  text-align: center;

  position: absolute;
  left: 0;
  right: 0;
  top: 50%;
  transform: translateY(-50%);
}

#container strong {
  font-size: 20px;
  line-height: 26px;
}

#container p {
  font-size: 16px;
  line-height: 22px;

  color: #8c8c8c;

  margin: 0;
}

#container a {
  text-decoration: none;
}
</style>
