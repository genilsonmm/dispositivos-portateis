<template>
  <ion-page>
    <ion-header :translucent="true">
      <ion-toolbar>
        <ion-title>ToDo</ion-title>
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
          <ion-card-title>Cadastro</ion-card-title>
        </ion-card-header>
        <ion-card-content>
          <ion-input v-model="input" @keydown.enter="confirm" label="Atividade" label-placement="floating" fill="outline"
            placeholder="Atividade"></ion-input>
          <ion-button @click="confirm" expand="block">Adicionar</ion-button>
        </ion-card-content>
      </ion-card>

      <ion-card>
        <ion-list>
          <ion-item @click="goToDetail(item.id)" v-for="(item, index) in tasks" :key="index">
            <ion-label>{{ item.activity }}</ion-label>
          </ion-item>
        </ion-list>
      </ion-card>

      <ion-note color="danger">
       <p class="note">https://github.com/ionic-team/ionic-storage?tab=readme-ov-file#api</p>
      </ion-note>
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
  IonInput,
  IonCard,
  IonCardHeader,
  IonCardTitle,
  IonCardContent,
  IonButton,
  IonNote,
  IonItem, IonLabel, IonList
} from '@ionic/vue';
import { reactive, ref, onMounted } from 'vue';
import { Task } from '@/model/task';
import { Messages } from '@/model/messages';
import { Storage } from '@ionic/storage';

import { useRouter } from 'vue-router';
const router = useRouter()

const input = ref<string>('')
const tasks = reactive<Task[]>([])
const store = new Storage();
const db_table = 'tasks';

onMounted(async () => {
  await store.create()
  await updateList()
})

async function confirm() {
  if (input.value == '') {
    alert(Messages.VALIDATION)
    input.value = ''
    return
  }

  await add({ id: new Date().getTime(), activity: input.value})
  await updateList()


  input.value = ''
}

async function add(task: Task) {
  tasks.push(task)
  await store.set(db_table, JSON.stringify(tasks))
}

async function updateList() {
  const db = await store.get(db_table)
  if(db) {
    const tableValues = JSON.parse(db)
    tasks.splice(0, tasks.length)
    tableValues.forEach((element: Task) => tasks.push(element));
    tasks.reverse()
  }
}

function goToDetail(index: number) {
  router.push(`/detail/${index}`)
}

</script>

<style scoped>
.note {
  text-align: center;
}
</style>
