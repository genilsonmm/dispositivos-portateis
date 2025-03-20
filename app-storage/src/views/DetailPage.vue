<template>
    <ion-page>
      <ion-header :translucent="true">
        <ion-toolbar>
          <ion-title>ToDo</ion-title>
          <ion-buttons slot="start">
            <ion-back-button default-href="/"></ion-back-button>
          </ion-buttons>
        </ion-toolbar>
      </ion-header>

      <ion-content :fullscreen="true">
        <ion-header collapse="condense">
            <ion-toolbar>
            <ion-title size="large">Blank</ion-title>
            </ion-toolbar>
        </ion-header>
        <ion-card>
            <ion-card-header>
                <ion-card-title>Detalhes</ion-card-title>
            </ion-card-header>
            <ion-card-content>
                <h2>ID: {{ task?.id }}</h2>
                <h2>Atividade: {{ task?.activity }}</h2>
            </ion-card-content>
        </ion-card>        
      </ion-content>
    </ion-page>
</template>

<script setup lang="ts">
import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonButtons,
  IonBackButton,
  IonCard,
  IonCardHeader,
  IonCardTitle,
  IonCardContent
} from '@ionic/vue';
import { onMounted, ref } from 'vue';
import { useRoute } from 'vue-router'

import { Storage } from '@ionic/storage';
import { Task } from '@/model/task';

const route = useRoute(); 
const task = ref<Task>({} as Task)

onMounted(async () => {
    const id: number = Number(route.params.id)

    const store = new Storage();
    await store.create()
    const db = await store.get('tasks')

    if(db) {
        const tableValues = JSON.parse(db) as Task[]
        task.value = tableValues.find(item => item.id == id) as Task
    }
})

</script>
