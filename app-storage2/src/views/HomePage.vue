<template>
  <ion-page>
    <ion-header :translucent="true">
      <ion-toolbar>
        <ion-title>Blank</ion-title>
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
          <ion-card-title>
            Cadastrar
          </ion-card-title>
        </ion-card-header>
        <ion-card-content>
          <ion-input v-model="input" label="Atividade" label-placement="floating" fill="outline"
            placeholder="Atividade"></ion-input>
          <ion-button @click="confirm" expand="block">Cadastrar</ion-button>
        </ion-card-content>
      </ion-card>
      <ion-card>
        <ion-list>
          <ion-item v-for="item in tasks" :key="item.id">
            <ion-label>{{ item.activity }}</ion-label>
          </ion-item>
        </ion-list>
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
  IonCard,
  IonCardHeader,
  IonCardTitle,
  IonCardContent,
  IonInput,
  IonButton,
  IonList,
  IonItem,
  IonLabel
} from '@ionic/vue';
import { Storage } from '@ionic/storage';
import { reactive, ref, onMounted } from 'vue';
import { Task } from '@/model/task';

const storage = new Storage()
const tasks = reactive<Task[]>([]) 
const input = ref<string>('')
const db_table = 'tasks'

onMounted(async ()=>{
  await storage.create()
  await updateList()
})

async function updateList() {
  const tasksDb = await storage.get(db_table)

  if(tasksDb){
    const tableValues = JSON.parse(tasksDb)
    tableValues.forEach((element: Task) => tasks.push(element));  
    tasks.reverse()
  }
}

function confirm() {
  console.log('input', input.value)
  if(input.value == ''){
    alert('Digite uma atividade')
    return
  }

  const task: Task = { id: new Date().getTime(), 
    activity: input.value 
  } 

  add(task)
  input.value = ''
  tasks.reverse()
}

async function add(task: Task) {
  tasks.push(task)
  await storage.set(db_table, JSON.stringify(tasks))
}

</script>

<style scoped>
</style>
